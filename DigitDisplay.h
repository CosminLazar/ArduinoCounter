// DigitDisplay.h

#ifndef _DIGITDISPLAY_h
#define _DIGITDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class DigitDisplay {
private:
	//Defines the conversion between an ASCII character to a byte representing the segments that need to be lit on the display
	//The table encodes ASCII characters ranging from '0' (decimal 48) to 'Z' (decimal 90)
	//The table is zero based, therefore to obtain the segments byte for a particular supported character you need to take the decimal code of the character - 48
	//e.g.: the position for the 'A' character is 17 (65-48)
	//Anything outside the supported range will cause the display to go blank
	uint8_t ConversionTable[43] = {
	/* [0] - 0		*/ 126,
	/* [1] - 1		*/ 48,
	/* [2] - 2		*/ 109,
	/* [3] - 3		*/ 121,
	/* [4] - 4		*/ 51,
	/* [5] - 5		*/ 91,
	/* [6] - 6		*/ 95,
	/* [7] - 7		*/ 114,
	/* [8] - 8		*/ 127,
	/* [9] - 9		*/ 123,
	/* [10] - :		*/ 72,
	/* [11] - ;		*/ 88,
	/* [12] - <		*/ 67,
	/* [13] - =		*/ 9,
	/* [14] - >		*/ 97,
	/* [15] - ?		*/ 101,
	/* [16] - @		*/ 125,
	/* [17] - A		*/ 119,
	/* [18] - B		*/ 127,
	/* [19] - C		*/ 78,
	/* [20] - D		*/ 61,
	/* [21] - E		*/ 79,
	/* [22] - F		*/ 71,
	/* [23] - G		*/ 94,
	/* [24] - H		*/ 55,
	/* [25] - I		*/ 6,
	/* [26] - J		*/ 60,
	/* [27] - K		*/ 87,
	/* [28] - L		*/ 14,
	/* [29] - M		*/ 84,
	/* [30] - N		*/ 118,
	/* [31] - O		*/ 126,
	/* [32] - P		*/ 103,
	/* [33] - Q		*/ 107,
	/* [34] - R		*/ 102,
	/* [35] - S		*/ 91,
	/* [36] - T		*/ 15,
	/* [37] - U		*/ 62,
	/* [38] - V		*/ 62,
	/* [39] - W		*/ 42,
	/* [40] - X		*/ 55,
	/* [41] - Y		*/ 59,
	/* [42] - Z		*/ 109
	};
public:
	void Display(char character);
};

#endif

