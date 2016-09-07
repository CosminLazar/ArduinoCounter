// AutoScrollingDisplay.h

#ifndef _AUTOSCROLLINGDISPLAY_h
#define _AUTOSCROLLINGDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DigitDisplay.h"
#include "DigitDisplayDecorator.h"

class AutoScrollingDisplayClass : public DigitDisplayDecoratorClass
{
private:
	uint8_t _noOfVisibleDigits;

public:
	AutoScrollingDisplayClass(DigitDisplay * decorated, uint8_t noOfVisibleDigits)
		: DigitDisplayDecoratorClass(decorated),
		_noOfVisibleDigits(noOfVisibleDigits)
	{};
	void Display(String text);
	void Process();
};


#endif

