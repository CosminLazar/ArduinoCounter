#include "PushButton.h"

bool PushButtonClass::IsDepressed()
{
	return _state == DepressedState;
}

void PushButtonClass::Process()
{
	DebounceButtonState();
}

void PushButtonClass::DebounceButtonState()
{
	bool isDepressed = digitalRead(_pin) == _depressedState;
	_state = (_state << 1) | (isDepressed ? 0 : 1) | UpperLimitMask;
}
