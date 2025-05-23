//Link , 23x13px
const unsigned char LinkAp [] PROGMEM = {
	0x00, 0x00, 0x00, 0x07, 0x0f, 0xc0, 0x1c, 0x18, 0x70, 0x30, 0x30, 0x18, 0x20, 0x60, 0x08, 0x60, 
	0x40, 0x0c, 0x40, 0x44, 0x04, 0x60, 0x04, 0x0c, 0x20, 0x0c, 0x08, 0x30, 0x18, 0x18, 0x18, 0x30, 
	0x30, 0x0f, 0xe1, 0xe0, 0x00, 0x00, 0x00
};

// 'LinkSlash', 16x13px
const unsigned char LinkSlash [] PROGMEM = {
	0x60, 0x00, 0x30, 0x00, 0x18, 0x30, 0x3c, 0xfc, 0x66, 0x06, 0xc3, 0x03, 0xc3, 0x83, 0xc0, 0xc3, 
	0x60, 0xe6, 0x3f, 0xb0, 0x0e, 0x18, 0x00, 0x0c, 0x00, 0x06
};

// 'Sensor', 23x13px
const unsigned char Sensor [] PROGMEM = {
	0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x0c, 0x00, 0x60, 0x19, 0x01, 0x30, 0x13, 0x39, 0x90, 0x32, 
	0x7c, 0x98, 0x32, 0x7c, 0x98, 0x32, 0x7c, 0x98, 0x13, 0x39, 0x90, 0x19, 0x01, 0x30, 0x0c, 0x00, 
	0x60, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00
};

// 'SS_no', 23x13px
const unsigned char SS_no [] PROGMEM = {
	0x80, 0x00, 0x00, 0x64, 0x00, 0x40, 0x1c, 0x00, 0x60, 0x1f, 0x01, 0x30, 0x13, 0xb9, 0x90, 0x32, 
	0x7c, 0x98, 0x32, 0x7c, 0x98, 0x32, 0x7c, 0x98, 0x13, 0x3b, 0x90, 0x19, 0x01, 0xf0, 0x0c, 0x00, 
	0x70, 0x04, 0x00, 0x4c, 0x00, 0x00, 0x02
};

// 'Signal', 18x13px
const unsigned char Signal [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x1b, 0x00, 0x00, 
	0xdb, 0x00, 0x00, 0xdb, 0x00, 0x00, 0xdb, 0x00, 0x06, 0xdb, 0x00, 0x06, 0xdb, 0x00, 0x36, 0xdb, 
	0x00, 0x36, 0xdb, 0x00, 0x00, 0x00, 0x00
};
// 'Ss_Failed', 128x25px
const unsigned char Ss_Failed [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0x83, 0xf9, 0x83, 0x07, 0x80, 0xf0, 0x3f, 0x00, 0x7f, 0x0c, 0x0c, 0x20, 0x3f, 0x8f, 0xc0, 
	0x0f, 0xe7, 0xf9, 0xc3, 0x1f, 0xe3, 0xf8, 0x7f, 0x80, 0x7f, 0x1e, 0x0e, 0x70, 0x3f, 0x9f, 0xe0, 
	0x1c, 0x67, 0x01, 0xc3, 0x18, 0x63, 0x9c, 0x71, 0xc0, 0x60, 0x1e, 0x0e, 0x70, 0x30, 0x1c, 0x70, 
	0x18, 0x07, 0x01, 0xe3, 0x18, 0x07, 0x0e, 0x71, 0xc0, 0x60, 0x3f, 0x0e, 0x70, 0x30, 0x1c, 0x38, 
	0x1c, 0x07, 0x01, 0xe3, 0x1c, 0x07, 0x0e, 0x71, 0xc0, 0x60, 0x33, 0x0e, 0x70, 0x30, 0x1c, 0x38, 
	0x1f, 0x87, 0x01, 0xb3, 0x1f, 0x87, 0x0e, 0x71, 0x80, 0x7f, 0x33, 0x0e, 0x70, 0x30, 0x1c, 0x38, 
	0x0f, 0xe7, 0xf1, 0x9b, 0x0f, 0xc6, 0x0e, 0x7f, 0x00, 0x7f, 0x73, 0x8e, 0x70, 0x3f, 0x9c, 0x38, 
	0x03, 0xe7, 0xf1, 0x9b, 0x03, 0xe7, 0x0e, 0x7f, 0x80, 0x60, 0x63, 0x8e, 0x70, 0x3f, 0x9c, 0x38, 
	0x00, 0xe7, 0x01, 0x8f, 0x00, 0xe7, 0x0e, 0x71, 0xc0, 0x60, 0x7f, 0x8e, 0x70, 0x30, 0x1c, 0x38, 
	0x00, 0x67, 0x01, 0x8f, 0x00, 0x67, 0x0e, 0x71, 0xc0, 0x60, 0xff, 0x8e, 0x70, 0x30, 0x1c, 0x38, 
	0x18, 0x67, 0x01, 0x87, 0x18, 0xe3, 0x9c, 0x71, 0xc0, 0x60, 0xe1, 0xce, 0x70, 0x30, 0x1c, 0x70, 
	0x1f, 0xe7, 0xf9, 0x87, 0x1f, 0xc3, 0xf8, 0x71, 0xc0, 0x60, 0xc1, 0xce, 0x7f, 0x3f, 0x9f, 0xe0, 
	0x07, 0x83, 0xf9, 0x83, 0x0f, 0x80, 0xf0, 0x20, 0x80, 0x60, 0xc0, 0xcc, 0x3f, 0x3f, 0x8f, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Wifi', 19x13px
const unsigned char Wifi [] PROGMEM = {
	0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x0f, 0xfe, 0x00, 0x18, 0x03, 0x00, 0x30, 0x01, 0x80, 0x03, 
	0xf8, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00
};

const unsigned char bitmap_logo [] PROGMEM = {
	0x00, 0x00, 0x1e, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x1f, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x70, 0xff, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x1f, 0x00, 0x00, 
	0x00, 0x01, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x3f, 0x80, 0x00, 
	0x00, 0x03, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x7f, 0xe0, 0x00, 
	0x00, 0x0f, 0xfe, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x7f, 0xf8, 0x00, 
	0x00, 0x3f, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 
	0x00, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 
	0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xf0, 
	0x1f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xe3, 
	0xc1, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x83, 0xc0, 0x7f, 0xff, 0xf8, 0x1f, 0xff, 0xfe, 0x03, 
	0x40, 0x0f, 0xff, 0xfc, 0x3f, 0xff, 0xf0, 0x02, 0x60, 0x03, 0xff, 0xfc, 0x3f, 0xff, 0xc0, 0x06, 
	0x60, 0x00, 0xff, 0xfc, 0x3f, 0xff, 0x00, 0x06, 0x60, 0x00, 0x1f, 0xfe, 0x7f, 0xf8, 0x00, 0x06, 
	0x60, 0x00, 0x07, 0xfe, 0x7f, 0xe0, 0x00, 0x06, 0x60, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x06, 
	0x60, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x06, 
	0x60, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x06, 
	0x60, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x06, 0x60, 0x00, 0x03, 0xfe, 0x7f, 0xc0, 0x00, 0x06, 
	0x60, 0x00, 0x0f, 0xfe, 0x7f, 0xf0, 0x00, 0x06, 0x60, 0x00, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x06, 
	0x60, 0x01, 0xff, 0xfc, 0x3f, 0xff, 0x80, 0x06, 0x40, 0x07, 0xff, 0xfc, 0x3f, 0xff, 0xe0, 0x02, 
	0xc0, 0x3f, 0xff, 0xf8, 0x1f, 0xff, 0xfc, 0x02, 0xc0, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x03, 
	0xc7, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xe3, 0x9f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xfb, 
	0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xfc, 
	0x0f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xe0, 
	0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0x1f, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x7f, 0xf0, 0x00, 
	0x00, 0x07, 0xfe, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00, 
	0x00, 0x03, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 
	0x00, 0x00, 0xf8, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0xfc, 0x1f, 0x00, 0x00, 
	0x00, 0x00, 0x77, 0xff, 0xff, 0xee, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x01, 0xfc, 0x00, 0x00
};

// 'AUTO', 60x14px
const unsigned char  AUTO [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0x04, 0x27, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x07, 0x8e, 0x77, 0xf7, 0xe0, 0x00, 0x00, 0x00, 
	0x07, 0x8e, 0x71, 0x8e, 0x70, 0x00, 0x00, 0x00, 0x06, 0xce, 0x71, 0x8c, 0x30, 0x00, 0x00, 0x00, 
	0x0c, 0xce, 0x71, 0x8c, 0x30, 0x00, 0x00, 0x00, 0x0c, 0xce, 0x71, 0x8c, 0x30, 0x00, 0x00, 0x00, 
	0x0f, 0xce, 0x71, 0x8c, 0x30, 0x00, 0x00, 0x00, 0x1f, 0xee, 0x71, 0x8e, 0x70, 0x00, 0x00, 0x00, 
	0x18, 0x67, 0xe1, 0x87, 0xe0, 0x00, 0x00, 0x00, 0x18, 0x63, 0xc1, 0x83, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'MANUAL', 60x14px
const unsigned char  MANUAL [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x18, 0x30, 0x70, 0xc3, 0x31, 0x87, 0x0c, 0x00, 0x1c, 0x38, 0x70, 0xe3, 0x31, 0x87, 0x0c, 0x00, 
	0x1c, 0x78, 0x78, 0xe3, 0x31, 0x8f, 0x0c, 0x00, 0x1c, 0x78, 0xd8, 0xf3, 0x31, 0x8d, 0x8c, 0x00, 
	0x1e, 0x58, 0xd8, 0xdb, 0x31, 0x8d, 0x8c, 0x00, 0x1a, 0x58, 0x8c, 0xdb, 0x31, 0x99, 0x8c, 0x00, 
	0x1a, 0xd9, 0xfc, 0xcf, 0x31, 0x9f, 0xcc, 0x00, 0x1b, 0x99, 0xfc, 0xc7, 0x39, 0x9f, 0xcc, 0x00, 
	0x1b, 0x99, 0x8e, 0xc7, 0x3f, 0xb8, 0xcf, 0xc0, 0x11, 0x99, 0x06, 0xc3, 0x1f, 0x30, 0x4f, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char headlights_off [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xe0, 0x00, 
	0x0f, 0xff, 0xe0, 0x00, 0x1f, 0x00, 0xe0, 0x00, 0x3c, 0x00, 0xe2, 0x08, 0x38, 0x00, 0xe6, 0x1c, 
	0x78, 0x00, 0xef, 0x3c, 0x70, 0x00, 0xef, 0xfc, 0x70, 0x00, 0xe7, 0xfc, 0xf0, 0x00, 0xe3, 0xf8, 
	0xf0, 0x00, 0xe3, 0xf0, 0x70, 0x00, 0xe7, 0xfc, 0x70, 0x00, 0xef, 0xfc, 0x70, 0x00, 0xef, 0xbe, 
	0x38, 0x00, 0xe7, 0x1c, 0x3c, 0x00, 0xe2, 0x08, 0x1e, 0x00, 0xe0, 0x00, 0x0f, 0xc1, 0xe0, 0x00, 
	0x07, 0xff, 0xe0, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char headlights_on [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xe0, 0x00, 
	0x0f, 0xff, 0xe0, 0x00, 0x1f, 0x00, 0xe7, 0xff, 0x3c, 0x00, 0xe7, 0xff, 0x38, 0x00, 0xe3, 0xfe, 
	0x78, 0x00, 0xe0, 0x00, 0x70, 0x00, 0xe0, 0x00, 0x70, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xe7, 0xff, 
	0xf0, 0x00, 0xe7, 0xff, 0x70, 0x00, 0xe3, 0xfe, 0x70, 0x00, 0xe0, 0x00, 0x70, 0x00, 0xe0, 0x00, 
	0x38, 0x00, 0xe0, 0x00, 0x3c, 0x00, 0xe7, 0xfe, 0x1e, 0x00, 0xe7, 0xff, 0x0f, 0xc1, 0xe3, 0xfe, 
	0x07, 0xff, 0xe0, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char engine [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xe0, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x00, 0x00, 0x0e, 0xc0, 
	0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x00, 0x0f, 0xc0, 0x07, 0xe0, 
	0x00, 0x0f, 0x00, 0x01, 0xff, 0x80, 0xcc, 0x00, 0x00, 0xdf, 0x80, 0xcc, 0x00, 0x00, 0xf8, 0xc0, 
	0xcc, 0x00, 0x00, 0xf8, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0xc0, 0xcc, 
	0x00, 0x00, 0x00, 0xc0, 0xcc, 0x00, 0x00, 0x00, 0xc0, 0xcc, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xc0, 
	0x00, 0xf8, 0xc0, 0x0f, 0xe0, 0x00, 0xf8, 0xc0, 0x0f, 0xf0, 0x00, 0xf9, 0xc0, 0x00, 0x3c, 0x00, 
	0xdf, 0x80, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
