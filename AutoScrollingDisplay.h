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
	const char WhiteSpace = ' ';
	uint8_t _noOfVisibleDigits;	
	String _textToDisplay;
	unsigned long _lastFrameDrawnAt = 0;
	int _lastFrameIndex = 0;
	uint16_t _scrollSpeed;
public:
	AutoScrollingDisplayClass(DigitDisplay * decorated, uint8_t noOfVisibleDigits, uint16_t scrollSpeed)
		: DigitDisplayDecoratorClass(decorated),
		_noOfVisibleDigits(noOfVisibleDigits),
		_scrollSpeed(scrollSpeed)
	{};
	void Display(String text);
	void Process();
private:
	void DrawFrame();
	void AfterFrameDraw();
	bool TimeForANewFrame();
};


#endif

