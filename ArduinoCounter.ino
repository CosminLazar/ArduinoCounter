#include "PushButton.h"
#include "AutoScrollingDisplay.h"
#include "DigitDisplayDecorator.h"
#include "MultiplexedDisplay.h"
#include "DigitDisplay.h"


Segments segmentConfig = { 11, 10, 9, 8, 7, 6, 5, 4 };
uint8_t digitSelectors[] = { 13, 12 };
DigitDisplay display(segmentConfig);

AutoScrollingDisplayClass * sdisplay = new AutoScrollingDisplayClass(new MultiplexedDisplay(&display, segmentConfig, digitSelectors, 2), 2, 200);

PushButtonClass increase(2, LOW);
PushButtonClass decrease(3, LOW);
uint8_t currentNumber = 0;

void setup()
{
	pinMode(3, INPUT_PULLUP);
	pinMode(2, INPUT_PULLUP);
	sdisplay->Display("123456789");
}

void loop()
{
	increase.Process();
	decrease.Process();
	sdisplay->Process();

	if (increase.IsDepressed()) {
		currentNumber = currentNumber == 256 ? 256 : ++currentNumber;
	}
	else if (decrease.IsDepressed()) {
		currentNumber = currentNumber == 0 ? 0 : --currentNumber;;
	}
	sdisplay->Display(String(currentNumber));
	delay(10);
}
