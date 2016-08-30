// 
// 
// 


#include "DigitDisplay.h"


void DigitDisplay::Display(char character)
{	
	uint8_t valueToDisplay = Convert(character);
	
	if (valueToDisplay & (1 << 6)) {
		//11 on
		digitalWrite(11, LOW);
	}
	else
	{
		//11 off
		digitalWrite(11, HIGH);
	}


	if (valueToDisplay & (1 << 5)) {
		//10 on
		digitalWrite(10, LOW);
	}
	else
	{
		//10 off
		digitalWrite(10, HIGH);
	}

	if (valueToDisplay & (1 << 4)) {
		//9 on
		digitalWrite(9, LOW);
	}
	else
	{
		//9 off
		digitalWrite(9, HIGH);
	}

	if (valueToDisplay & (1 << 3)) {
		//8 on
		digitalWrite(8, LOW);
	}
	else
	{
		//8 off
		digitalWrite(8, HIGH);
	}

	if (valueToDisplay & (1 << 2)) {
		//7 on
		digitalWrite(7, LOW);
	}
	else
	{
		//7 off
		digitalWrite(7, HIGH);
	}

	if (valueToDisplay & (1 << 1)) {
		//6 on
		digitalWrite(6, LOW);
	}
	else
	{
		//6 off
		digitalWrite(6, HIGH);
	}

	if (valueToDisplay & 1) {
		//5 on
		digitalWrite(5, LOW);
	}
	else
	{
		//5 off
		digitalWrite(5, HIGH);
	}
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
