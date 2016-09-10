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
	sdisplay->Display("123456789");
}

void loop()
{
	sdisplay->Process();
	delay(10);
}
