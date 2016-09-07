// 
// 
// 

#include "MultiplexedDisplay.h"
String textToDisplay = "";
void MultiplexedDisplay::Display(String text)
{	
	textToDisplay = text;	
	DigitDisplayDecoratorClass::Display(text);
}

void MultiplexedDisplay::Process()
{
	//1. turn off active digit
	//2. set the state for the next digit
	//3. turn on (make active) the next digit

	digitalWrite(_digitSelectors[_currentDigitIndex], LOW);

	_currentDigitIndex = (_currentDigitIndex + 1) % _digitSelectorsLen;

	char characterToDisplay = _currentDigitIndex < textToDisplay.length()
								? textToDisplay[_currentDigitIndex]
								: ' ';
	
	DigitDisplayDecoratorClass::Display(String(characterToDisplay));

	digitalWrite(_digitSelectors[_currentDigitIndex], HIGH);
}
