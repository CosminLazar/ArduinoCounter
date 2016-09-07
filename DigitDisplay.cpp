// 
// 
// 


#include "DigitDisplay.h"

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