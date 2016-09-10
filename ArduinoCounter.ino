#include "AutoScrollingDisplay.h"
#include "DigitDisplayDecorator.h"
#include "MultiplexedDisplay.h"
#include "DigitDisplay.h"


Segments segmentConfig = { 11, 10, 9, 8, 7, 6, 5, 4 };
uint8_t digitSelectors[] = { 13, 12 };
DigitDisplay display(segmentConfig);

AutoScrollingDisplayClass * sdisplay = new AutoScrollingDisplayClass(new MultiplexedDisplay(&display, segmentConfig, digitSelectors, 2), 2, 200);

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

	Serial.begin(9600);

	sdisplay->Display("123456789");
}

void loop()
{
	sdisplay->Process();
	delay(10);
}
