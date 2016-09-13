#include "PushButton.h"
#include "AutoScrollingDisplay.h"
#include "DigitDisplayDecorator.h"
#include "MultiplexedDisplay.h"
#include "DigitDisplay.h"
#include <EEPROM.h>

const uint8_t noOfSegments = 2;

//Format for padding single digit numbers with space
const String displayFormat = "%" + String(noOfSegments) + "s";
Segments segmentConfig = { 11, 10, 9, 8, 7, 6, 5, 4 };
uint8_t digitSelectors[] = { 13, 12 };
DigitDisplay display(segmentConfig);
AutoScrollingDisplayClass * sdisplay = new AutoScrollingDisplayClass(new MultiplexedDisplay(&display, segmentConfig, digitSelectors, noOfSegments), noOfSegments, 200);
PushButtonClass increase(2, LOW);
PushButtonClass decrease(3, LOW);
uint8_t currentNumber = 0;

void setup()
{
	pinMode(3, INPUT_PULLUP);
	pinMode(2, INPUT_PULLUP);

	SplashScreen();
	InitializeFromFlash();
	RefreshDisplay();
}

void loop()
{
	increase.Process();
	decrease.Process();
	sdisplay->Process();

	if (increase.IsDepressed()) {
		UpdateCurrentNumber(currentNumber == 256 ? 256 : currentNumber + 1);
		RefreshDisplay();
	}
	else if (decrease.IsDepressed()) {
		UpdateCurrentNumber(currentNumber == 0 ? 0 : currentNumber - 1);
		RefreshDisplay();
	}

	delay(7);
}

void InitializeFromFlash()
{
	EEPROM.get(0, currentNumber);

	//255 means byte is not set
	if (currentNumber == 255)
		currentNumber = 0;
}

void UpdateCurrentNumber(uint8_t newValue)
{
	currentNumber = newValue;
	EEPROM.write(0, currentNumber);
}

void RefreshDisplay() {
	char text[3];//we are limited at 256 anyway	
	sprintf(text, displayFormat.c_str(), String(currentNumber).c_str());
	sdisplay->Display(String(text));
}

void SplashScreen()
{
	unsigned long start = millis();
	sdisplay->Display("TRANS4MERS");

	while (millis() - start < 5200)
	{
		sdisplay->Process();
	}
}