// 
// 
// 

#include "MultiplexedDisplay.h"
String textToDisplay = "";
void MultiplexedDisplay::Display(String text)
{
	textToDisplay = text;
	//_digitDisplay.Display(text[0]);
}
uint8_t charToDisplay = 0;

void MultiplexedDisplay::Process()
{
	//1. turn off active digit
	//2. set the state for the next digit
	//3. turn on (make active) the next digit

	if (charToDisplay == 0)
	{
		digitalWrite(12, LOW);
		_digitDisplay.Display(textToDisplay[0]);
		digitalWrite(13, HIGH);
	}
	else {
		digitalWrite(13, LOW);
		_digitDisplay.Display(textToDisplay[1]);
		digitalWrite(12, HIGH);

	}
	charToDisplay = (charToDisplay + 1) % 2;
}
