// 
// 
// 

#include "DigitDisplayDecorator.h"

void DigitDisplayDecoratorClass::Display(String text)
{	
	_digitDisplay->Display(text);
}

void DigitDisplayDecoratorClass::Process()
{
	_digitDisplay->Process();
}
