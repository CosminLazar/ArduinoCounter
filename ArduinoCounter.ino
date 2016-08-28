#include "DigitDisplay.h"
void setup()
{

	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);

	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);


	digitalWrite(13, HIGH);
	digitalWrite(12, LOW);


	digitalWrite(11, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(9, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
}

DigitDisplay display;

void loop()
{

	display.Display('Z');

	//delay(500);
 // /* add main program code here */
	//display.Display('0');

	//delay(500);

	//display.Display('1');

	//delay(500);
	//display.Display('2');

	//delay(500);
	//display.Display('3');

	//delay(500);
	//display.Display('4');

	//delay(500);
	//display.Display('5');

	//delay(500);
	//display.Display('6');

	//delay(500);
	//display.Display('7');

	//delay(500);
	//display.Display('8');

	//delay(500);
	//display.Display('9');
}
