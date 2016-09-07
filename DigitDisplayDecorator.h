// DigitDisplayDecorator.h

#ifndef _DIGITDISPLAYDECORATOR_h
#define _DIGITDISPLAYDECORATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DigitDisplay.h"

class DigitDisplayDecoratorClass : public DigitDisplay
{
private:
	DigitDisplay * _digitDisplay;

public:
	DigitDisplayDecoratorClass(DigitDisplay * decoratedItem) 
		:_digitDisplay(decoratedItem) {};
	 void Display(String text) ;
	 void Process() ;
};

#endif

