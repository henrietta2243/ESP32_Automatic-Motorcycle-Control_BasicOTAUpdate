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
#include "my_bitmap.h"
#include "image.h"
#include <segoeuithibd12pt7b.h>

//AP mode 
#define SSID_FORMAT "ESP32-%06lX"  // 12 chars total
//#define PASSWORD "test123456"    // uncomment this for AP password

//Oled setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//AP 
const char *alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
String generatePass(uint8_t str_len) {
  String buff;
  for (int i = 0; i < str_len; i++) {
    buff += alphanum[random(strlen(alphanum) - 1)];
  }
  return buff;
}

void apMode() {
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
}

/* Place your code here */
// Pin definitions
#define LDR_PIN 36     
#define RELAY_PIN 27    
#define BUTTON_PIN 15   
#define LED_PIN 14      
#define SENSOR_FAIL_LED 13 

// Constants
#define THRESHOLD 2000
#define LONG_PRESS_TIME 1500
#define LDR_MIN 10
#define LDR_MAX 4000
#define FRAME_DELAY (42)
#define FRAME_WIDTH (32)
#define FRAME_HEIGHT (32)
#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))

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

void setup()
{
	Serial.begin(115200);
	Serial.println("Booting");
	apMode();
	Serial.print("local IP address: ");
	Serial.println(WiFi.softAPIP());

	// Port defaults to 3232
	ArduinoOTA.setPort(3232);

	// Hostname defaults to esp3232-[MAC]
	ArduinoOTA.setHostname("myesp32-OTA");

	// No authentication by default
	// ArduinoOTA.setPassword("admin");

	// Password can be set with it's md5 value as well
	// MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
	// ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
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
	ArduinoOTA.begin();

	Serial.println("Ready");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

    /* Place your setup here */
	// Pin setup
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    pinMode(SENSOR_FAIL_LED, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(SENSOR_FAIL_LED, HIGH);
    
    // OLED init
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Default I2C address
        Serial.println(F("OLED init failed"));
        while (true);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.drawBitmap(32, 0, bitmap_logo, 64, 64, WHITE); 
    display.display();
    delay(1000);
    display.clearDisplay();
    for (int frame = 0; frame < 35; frame++) {
    display.clearDisplay();

    // Draw the bitmap from PROGMEM
    display.drawBitmap(0, 17, loading_frm[frame], 128, 32, WHITE);
    display.display();

    delay(100);  // Frame delay (100 ms)
  }
    delay(500);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(SENSOR_FAIL_LED, LOW);
}

void loop()
{
	ArduinoOTA.handle();

    /* Place your loop below */
    //This loop for Automatic Motorcycle Headlight with 128x64 OLED Disply
	static bool lastRelayState = HIGH;

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

    // Button handling
    if (digitalRead(BUTTON_PIN) == LOW) {
        if (buttonPressTime == 0) {
            buttonPressTime = millis();
        }

        if (millis() - buttonPressTime > LONG_PRESS_TIME && !buttonHeld) {
            manualMode = !manualMode;
            Serial.println(manualMode ? "Manual Mode ON" : "Automatic Mode ON");
            digitalWrite(LED_PIN, manualMode ? HIGH : LOW);
            buttonHeld = true;
        }
        delay(10);
    } else {
        if (buttonPressTime > 0 && millis() - buttonPressTime < LONG_PRESS_TIME && !buttonHeld) {
            if (manualMode) {
                headlightState = !headlightState;
                Serial.println(headlightState ? "Headlight ON" : "Headlight OFF");
            }
        }
        buttonPressTime = 0;
        buttonHeld = false;
        delay(10);
    }

    // Automatic mode control
    if (!manualMode) {
        headlightState = (lightValue < THRESHOLD);
    }

    // Update relay if needed
    if (headlightState != lastRelayState) {
        digitalWrite(RELAY_PIN, headlightState ? LOW : HIGH);
        lastRelayState = headlightState;
    }

    // OLED Display update
    display.clearDisplay();
    display.drawBitmap(0, 0, manualMode ? manual_mode : automatic_mode,32, 32, SSD1306_WHITE); 
		display.drawBitmap(45, 0, headlightState ? headlights_on : headlights_off,32, 32, SSD1306_WHITE);
		display.drawBitmap(94, 0,ldrFailed ? frames[frame] : wifi, FRAME_WIDTH, FRAME_HEIGHT, 1);
    if (ldrFailed) {
    display.drawBitmap(0, 32, ss_failed, 128, 32, SSD1306_WHITE);
    } else {
    display.setFont(&segoeuithibd12pt7b);
    display.setCursor(0, 50);  
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("LDR: ");
    display.println(lightValue);
}
    display.display();
		frame = (frame + 1) % FRAME_COUNT;

    //Serial.println(lightValue);  //Uncomment for calibrating LDR Value
    delay(50);
}