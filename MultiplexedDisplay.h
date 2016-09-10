// MultiplexedDisplay.h

#ifndef _MULTIPLEXEDDISPLAY_h
#define _MULTIPLEXEDDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DigitDisplay.h"
#include "DigitDisplayDecorator.h"

class MultiplexedDisplay : public DigitDisplayDecoratorClass {
private:
	uint8_t* _digitSelectors;
	uint8_t _digitSelectorsLen;
	uint8_t _currentDigitIndex = 0;
public:
	MultiplexedDisplay(DigitDisplay * decorated, Segments segmentSetup, uint8_t digitSelectors[], uint8_t digitSelectorsLen)
		: DigitDisplayDecoratorClass(decorated),
		_digitSelectors(digitSelectors),
		_digitSelectorsLen(digitSelectorsLen)
	{
		for (size_t i = 0; i < _digitSelectorsLen; i++)
		{
			pinMode(_digitSelectors[i], OUTPUT);
		}
	};
	void Display(String text);
	void Process();
};
#endif

