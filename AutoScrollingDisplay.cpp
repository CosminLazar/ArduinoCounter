#include "AutoScrollingDisplay.h"

void AutoScrollingDisplayClass::Display(String text)
{
	_textToDisplay = text;
}

void AutoScrollingDisplayClass::Process() {
	if (TimeForANewFrame())
	{
		DrawFrame();
		AfterFrameDraw();
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

		int leftPadding = _noOfVisibleDigits - _lastFrameIndex > 0
			? _noOfVisibleDigits - _lastFrameIndex
			: 0;

		for (size_t i = 0; i < _noOfVisibleDigits; i++)
		{
			if (i < leftPadding)
			{
				frameStr.concat(WhiteSpace);
			}
			else
			{
				int textIndexer = i + _lastFrameIndex - _noOfVisibleDigits;
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

void AutoScrollingDisplayClass::AfterFrameDraw() 
{
	_lastFrameDrawnAt = millis();
	unsigned int drawWindow = _textToDisplay.length() + _noOfVisibleDigits;
	_lastFrameIndex = (_lastFrameIndex + 1) % drawWindow;
}

bool AutoScrollingDisplayClass::TimeForANewFrame()
{
	return (millis() - _lastFrameDrawnAt) > _scrollSpeed;
}