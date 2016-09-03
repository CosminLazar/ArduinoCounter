// MultiplexedDisplay.h

#ifndef _MULTIPLEXEDDISPLAY_h
#define _MULTIPLEXEDDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DigitDisplay.h"

class MultiplexedDisplay {
private:
	DigitDisplay _digitDisplay;
public:
	MultiplexedDisplay(Segments segmentSetup) : _digitDisplay(DigitDisplay(segmentSetup)) {};
	void Display(String text);
	void Process();
};
#endif

