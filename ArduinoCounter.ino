#include "MultiplexedDisplay.h"
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
	pinMode(4, OUTPUT);

	//digitalWrite(13, HIGH);
	//digitalWrite(12, LOW);


	digitalWrite(11, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(9, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
}

Segments segmentConfig = { 11, 10, 9, 8, 7, 6, 5, 4 };

DigitDisplay display(segmentConfig);
MultiplexedDisplay mdisplay(segmentConfig);
bool t = false;
void loop()
{
	if (!t)
	{
		String str("123456");
		mdisplay.Display(str);
		t = true;
	}
	mdisplay.Process();	
}
