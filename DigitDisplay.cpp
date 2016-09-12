#include "DigitDisplay.h"
const uint8_t DigitDisplay::ConversionTable[ConversionTableLength] = {
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

void DigitDisplay::Display(String text)
{
	Display(text, false);
}

void DigitDisplay::Process()
{
}

void DigitDisplay::Display(String text, bool dpOn) {
	uint8_t valueToDisplay = Convert(text[0]);

	digitalWrite(_segmentSetup.A, IsBitSet(6, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.B, IsBitSet(5, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.C, IsBitSet(4, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.D, IsBitSet(3, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.E, IsBitSet(2, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.F, IsBitSet(1, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.G, IsBitSet(0, valueToDisplay) ? SegmentON : SegmentOFF);
	digitalWrite(_segmentSetup.H, dpOn ? SegmentON : SegmentOFF);
}

bool DigitDisplay::IsCharacterSupported(char character)
{
	if (ConversionTableLength == 0)
		return false;

	bool isSupported = (FirstSupportedCharacter <= character) && (character <= LastSupportedCharacter);
	return isSupported;
}

uint8_t DigitDisplay::Convert(char character)
{
	if (!IsCharacterSupported(character))
		return 0;

	uint8_t index = character - FirstSupportedCharacter;
	return ConversionTable[index];
}


bool DigitDisplay::IsBitSet(uint8_t bit, uint8_t byte) {
	return byte & (1 << bit);
}