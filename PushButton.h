// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class PushButtonClass
{
private:
	uint8_t _depressedState;
	uint8_t _pin;
	uint16_t _state = 0;
	//Mask to ignore bounces in the higher bits
	//Binary: ‭1110000000000000‬
	const uint16_t UpperLimitMask = 0xE000;

	//Depressed button state (12 consecutive non-bouncing reads)
	//Binary: ‭1111000000000000‬
	const uint16_t DepressedState = 0xF000;//12 repetitive
public:
	PushButtonClass(uint8_t pin, uint8_t depressedState)
		:_pin(pin),
		_depressedState(depressedState) {};

	//Returns true only once per button depressal
	bool IsDepressed();
	void Process();
private:
	void DebounceButtonState();
};


#endif

