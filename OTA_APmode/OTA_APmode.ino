/**

 Basic Arduino OTA AP mode
 Automatic Motorcycle Headlight Control
 
 **/
#include "Arduino.h"
#include "WiFi.h"
#include "ArduinoOTA.h"
#include <ESPmDNS.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "image.h"
#include "Image2.h"
#include <led_counter_712pt7b.h>
#include <OpenSauceOne_Medium7pt7b.h>
#include <Adafruit_ADS1X15.h>

//AP mode
#define SSID_FORMAT "ESP32-%06lX"  // 12 chars total
#define PASSWORD "test123456"      // AP password

//Oled setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// State variables
bool manualMode = false;
bool headlightState = false;
bool ldrFailed = false;
unsigned long buttonPressTime = 0;
bool buttonHeld = false;
unsigned long blinkTimer = 0;
bool blinkState = false;
const int blinkInterval = 500;
int frame = 0;
Adafruit_ADS1115 ads;
bool thresholdReached = false;
bool apStarted = false;
bool otaActive = false;
unsigned long apStartTime = 0;
const unsigned long apTimeout = 60000;  // 1 minute
unsigned long holdStartTime = 0;
bool showingBar = false;


//AP
const char *alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
String generatePass(uint8_t str_len) {
  String buff;
  for (int i = 0; i < str_len; i++) {
    buff += alphanum[random(strlen(alphanum) - 1)];
  }
  return buff;
}

void startAPMode() {
  char ssid[13];
  char passwd[11];
  long unsigned int espmac = ESP.getEfuseMac() >> 24;
  snprintf(ssid, 13, SSID_FORMAT, espmac);
#ifdef PASSWORD
  snprintf(passwd, 11, PASSWORD);
#else
  snprintf(passwd, 11, generatePass(10).c_str());
#endif
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, passwd);  // Set up the SoftAP
  MDNS.begin("esp32");
  Serial.printf("AP: %s, PASS: %s\n", ssid, passwd);
  ArduinoOTA.begin();
  apStartTime = millis();
  apStarted = true;
  otaActive = true;
}

void stopAPMode() {
  Serial.println("Stopping AP and WiFi...");
  if (apStarted) {
    animateWiFiOff();  // Animate before shutting down
  }

  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_OFF);
  apStarted = false;
  otaActive = false;
}

// Pin definitions
#define LDR_PIN 36
#define RELAY_PIN 27
#define BUTTON_PIN 15
#define LED_PIN 14
#define SENSOR_FAIL_LED 13
#define RELAY2_PIN 25
#define BYPASS_BTN 16

// Constants
#define THRESHOLD 2000
#define LONG_PRESS_TIME 1500
#define LDR_MIN 20
#define LDR_MAX 4000
#define MAX_HOLD_TIME 5000  // Max time to visualize

// Voltage Reading from ADS1115 I2C
float readVoltage() {
  int16_t adc0 = ads.readADC_SingleEnded(0);
  float voltage2 = adc0 * 0.125 / 1000.0 * 11.0;
  return voltage2;
}

int p1 = random(0, 100);

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  Wire.begin(21, 22);
  startAPMode();
  Serial.print("local IP address: ");
  Serial.println(WiFi.softAPIP());

  // Port defaults to 3232
  ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  ArduinoOTA.setHostname("myesp32-OTA");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else
        type = "filesystem";

      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR)
        Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR)
        Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR)
        Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR)
        Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR)
        Serial.println("End Failed");
    });

  ArduinoOTA.setTimeout(60000);

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Pin setup
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BYPASS_BTN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_FAIL_LED, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(RELAY2_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(SENSOR_FAIL_LED, HIGH);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Default I2C address
    Serial.println(F("OLED init failed"));
    while (true)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.drawBitmap(32, 0, bitmap_logo, 64, 64, SSD1306_WHITE);
  display.display();
  delay(1000);
  for (int frame = 0; frame < 35; frame++) {
    display.clearDisplay();

    // Draw the bitmap from PROGMEM
    display.drawBitmap(0, 17, loading_frm[frame], 128, 32, SSD1306_WHITE);
    display.display();

    delay(100);  // Frame delay (100 ms)
  }
  delay(500);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(SENSOR_FAIL_LED, LOW);
  ads.begin();            // default address 0x48
  ads.setGain(GAIN_ONE);  // ±4.096V range = 1 bit = 125uV
}

void loop() {
// Wait for Engine to Start Then Proceed Next Loop
   if (!thresholdReached){
        float voltage2 = readVoltage();

        if (voltage2 >= 13.5){
            digitalWrite(RELAY2_PIN, HIGH);
            thresholdReached = true;
        } else if(digitalRead(BYPASS_BTN) == LOW) {
          thresholdReached = true;
        } else {
            display.clearDisplay();
            display.setFont(&OpenSauceOne_Medium7pt7b);
            display.setCursor(0, 13);  
            display.print("START ENGINE"); display.drawBitmap(47, 15, engine, 34, 34, SSD1306_WHITE);
            drawPercentbar( 0, 49, 128, 15,p1);
            display.display();
            p1++;
            if( p1 > 100) p1 =0;
            
        }
        delay(500);
        return;
    }

// Loop After Engine Start
  ArduinoOTA.handle();
  if (apStarted && millis() - apStartTime > apTimeout && WiFi.softAPgetStationNum() == 0) {
    stopAPMode();
  }

  // Voltage Measurement
  int16_t adc0 = ads.readADC_SingleEnded(0);
  float voltage = adc0 * 0.125 / 1000.0 * 11.0;  // Compensate for divider

  static bool lastRelayState = headlightState;

  int lightValue = analogRead(LDR_PIN);

  // LDR failure detection
  if (lightValue < LDR_MIN || lightValue > LDR_MAX) {
    if (!ldrFailed) {
      Serial.println("LDR Failure Detected! Switching to Manual Mode.");
      ldrFailed = true;
      manualMode = true;
      digitalWrite(LED_PIN, HIGH);
    }
  } else {
    if (ldrFailed) {
      Serial.println("LDR Recovered! Auto Mode Available.");
      ldrFailed = false;
    }
  }

  // Sensor failure LED blinking
  if (ldrFailed) {
    if ((millis() - blinkTimer) >= blinkInterval) {
      blinkTimer = millis();
      blinkState = !blinkState;
      digitalWrite(SENSOR_FAIL_LED, blinkState);
    }
  } else {
    digitalWrite(SENSOR_FAIL_LED, LOW);
  }

  // Button handling with dual-function press
  static bool apRequested = false;
  bool showingBar = false;

  if (digitalRead(BUTTON_PIN) == LOW) {
    if (buttonPressTime == 0) {
      buttonPressTime = millis();
      holdStartTime = millis();
    }

    unsigned long heldTime = millis() - buttonPressTime;
    if (heldTime > 500) { 
      showingBar = true;
    }

    if (heldTime >= 5000 && !apRequested) {
      Serial.println("AP Mode Requested (5s press)");
      apRequested = true;
      if (!apStarted) {
        startAPMode();
      }
    } else if (heldTime >= 2000 && !buttonHeld && !apRequested) {
      manualMode = !manualMode;
      Serial.println(manualMode ? "Manual Mode ON" : "Automatic Mode ON");
      digitalWrite(LED_PIN, manualMode ? HIGH : LOW);
      buttonHeld = true;
    }

    delay(10);
  } else {
    if (buttonPressTime > 0 && (millis() - buttonPressTime) < 2000 && !buttonHeld) {
      if (manualMode) {
        headlightState = !headlightState;
        Serial.println(headlightState ? "Headlight ON" : "Headlight OFF");
      }
    }

    buttonPressTime = 0;
    buttonHeld = false;
    apRequested = false;
    //showingBar = false;
    delay(10);
  }

  // Automatic mode control
  if (!manualMode) {
    headlightState = (lightValue < THRESHOLD);
  }

  // Update relay if needed
  if (headlightState != lastRelayState) {
    digitalWrite(RELAY_PIN, headlightState ? HIGH : LOW);
    lastRelayState = headlightState;
  }

  // OLED Display update
  display.clearDisplay();
  display.drawBitmap(0, 0, manualMode ? MANUAL : AUTO, 60, 14, SSD1306_WHITE);
  display.drawBitmap(3, 13, headlightState ? headlights_on : headlights_off, 32, 32, SSD1306_WHITE);
  // Visual bar
  if (showingBar) {
    drawHoldProgressBar(millis() - holdStartTime);  // Just draws the bar
  }

  if (apStarted) {
    display.drawBitmap(110, 0, Wifi, 19, 13, SSD1306_WHITE);                      
    display.drawBitmap(87, 0, ldrFailed ? SS_no : Sensor, 23, 13, SSD1306_WHITE);  
    if (WiFi.softAPgetStationNum() == 0) {
      display.drawBitmap(65, 0, LinkSlash, 16, 13, SSD1306_WHITE);  // Client icon
    } else {
      display.drawBitmap(62, 0, LinkAp, 23, 13, SSD1306_WHITE);
    }
  } else {
    display.drawRect(110, 0, 19, 13, SSD1306_BLACK);  
    display.drawRect(62, 0, 23, 13, SSD1306_BLACK);
    display.drawBitmap(105, 0, ldrFailed ? SS_no : Sensor, 23, 13, SSD1306_WHITE);
  }

  if (ldrFailed) {
    display.drawBitmap(0, 39, Ss_Failed, 128, 32, SSD1306_WHITE);
    display.setFont(&led_counter_712pt7b);
    display.setCursor(45, 35);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print(voltage, 1);
    display.print(" V");
  } else {
    display.setFont(&led_counter_712pt7b);
    display.setCursor(0, 62);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print(voltage, 1);
    display.print(" Volt");
  }

  display.display();

  //Serial.println(lightValue);  //Uncomment for calibrating LDR Value
  delay(50);
}

// UI Function
// Progress Bar
void drawPercentbar(int x, int y, int width, int height, int progress) {
  progress = progress > 100 ? 100 : progress;
  progress = progress < 0 ? 0 : progress;

  float bar = ((float)(width - 4) / 100) * progress;

  display.drawRect(x, y, width, height, WHITE);
  display.fillRect(x + 2, y + 2, bar, height - 4, WHITE);
}

// Animation When Wifi Turn Off
void animateWiFiOff() {
  for (int x = 110; x < 128; x += 3) {
    display.fillRect(110, 0, 19, 13, SSD1306_BLACK);  
    display.drawBitmap(x, 0, Wifi, 19, 13, SSD1306_WHITE);
    display.display();
    delay(30);  // Frame delay
  }

  // Final clean-up to fully erase area
  display.fillRect(110, 0, 19, 13, SSD1306_BLACK);
  display.display();
}

// Progress Bar for Button Press Timing
void drawHoldProgressBar(unsigned long elapsed) {
  int percent = map(elapsed, 0, MAX_HOLD_TIME, 0, 100);
  drawPercentbar(37, 15, 90, 10, percent);
  // Tick mark at 2 seconds (40%)
  int tick2s = 37 + map(2000, 0, MAX_HOLD_TIME, 0, 90);
  display.drawLine(tick2s, 14, tick2s, 26, SSD1306_WHITE);

  // Tick mark at 5 seconds (100%)
  int tick5s = 37 + 86;

  display.drawLine(tick5s, 14, tick5s, 26, SSD1306_WHITE);
  display.setFont();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(tick2s - 5, 28);
  display.print("2s");
  display.setCursor(tick5s - 10, 28);
  display.print("5s");
}
