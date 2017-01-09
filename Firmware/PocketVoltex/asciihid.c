#include "asciihid.h"

/****************************************************************************
 *
 * ASCII->HID LOOKUP TABLE
 *	
 *	Taken from the HID Table definition at 
 * 		http://www.usb.org/developers/devclass_docs/Hut1_11.pdf
 * 	
 *  This array maps the ASCII value of a type-able character to its 
 *  corresponding HID value. 
 *
 *	Example:
 *		'a' = ASCII value 97 = HID value 0x04
 * 		HIDTable['a'] = HIDTable[97] = 0x04
 *
 * 	NOTE:
 *		"Shift Modified" HID values are the same as the non Shift-Modified values
 * 		for any given character, e.g. the HID value for '2' is equal to the 
 *		HID value for '@'. The Shift-Modified value is sent by setting the
 *		modifier value (buf[0]) to the corresponding modifier value in the 
 *    modifier table. 
 *
 ****************************************************************************/
const uint8_t PROGMEM HIDTable[]  =  {
	0x00, // 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x28, // 10
	0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 20
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, // 30
	0x00, 0x2c, 0x1e, 0x34, 0x20, 0x21, 0x22, 0x24, 0x34, 0x26, // 40
	0x27, 0x25, 0x2e, 0x36, 0x2d, 0x37, 0x38, 0x27, 0x1e, 0x1f, // 50
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x33, 0x33, 0x36, // 60
	0x2e, 0x37, 0x38, 0x1f, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, // 70
	0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, // 80
	0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, // 90
	0x2f, 0x31, 0x30, 0x23, 0x2d, 0x35, 0x04, 0x05, 0x06, 0x07, // 100
	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, // 110
	0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, // 120
	0x1c, 0x1d, 0x2f, 0x31, 0x30, 0x35, 127 // 127
};


/****************************************************************************
 * 
 * ASCII->MODIFIER LOOKUP TABLE
 * 
 * 	Looks up whether or not the HID report should use the SHIFT modifier. 
 * 
 * 	Example:
 *		The character '2' and the character '@' have different ASCII values but
 * 		the same HID value. This table uses the ASCII value to determine if 
 *		we should hold shift while sending the key. e.g.:
 *
 *			HIDTable['2'] = 0x1f  and  modifierTable['2'] = 0 
 *			HIDTable['@'] = 0x1f  and  modifierTable['@'] = SHIFT
 *
 *  There's probaly a better way to do this, but it's functional.
 *
 ****************************************************************************/
const uint8_t PROGMEM modifierTable[] = {
	0x00, // 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 10
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 20
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 30
  0x00, 0x00, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, 	// 40
  SHIFT, 0x00, SHIFT, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 				// 50
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, SHIFT, 0x00, SHIFT, 				// 60
  0x00, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, 	// 70
  SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, // 80
  SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, // 90
  0x00, 0x00, 0x00, SHIFT, SHIFT, 0x00, 0x00, 0x00, 0x00, 0x00, 				// 100
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 110
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 120
  0x00, 0x00, SHIFT, SHIFT, SHIFT, SHIFT, 0x00 // 127
};

const uint8_t PROGMEM numpadTable[] = {
    0x62, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61 // 0-9 on the numpad
};