#include "AutoScrollingDisplay.h"

void AutoScrollingDisplayClass::Display(String text)
{
	_textToDisplay = text;
}

void AutoScrollingDisplayClass::Process() {

	if ((millis() - lastFrame) > 200)
	{
		DrawFrame();
		lastFrame = millis();
		lastFrameIndex = (lastFrameIndex + 1) % (_textToDisplay.length() + 2);
	}

	DigitDisplayDecoratorClass::Process();
}

void AutoScrollingDisplayClass::DrawFrame()
{
	if (_textToDisplay.length() <= _noOfVisibleDigits)
	{
		DigitDisplayDecoratorClass::Display(_textToDisplay);
	}
	else
	{
		String frameStr = String();

		int leftPadding = _noOfVisibleDigits - lastFrameIndex > 0
			? _noOfVisibleDigits - lastFrameIndex
			: 0;

		for (size_t i = 0; i < _noOfVisibleDigits; i++)
		{
			if (i < leftPadding)
			{
				frameStr.concat(WhiteSpace);
			}
			else
			{
				int textIndexer = i + lastFrameIndex - _noOfVisibleDigits;
				if (textIndexer < _textToDisplay.length())
				{
					frameStr.concat(_textToDisplay[textIndexer]);
				}
				else
				{
					frameStr.concat(WhiteSpace);
				}
			}
		}

		DigitDisplayDecoratorClass::Display(frameStr);
	}
}
