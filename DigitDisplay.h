// DigitDisplay.h

#ifndef _DIGITDISPLAY_h
#define _DIGITDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

///<summary>Identifies the Arduino digital pins connected to each segment.</summary>
///<remarks>Use the segment_mapping.gif file in the literature directory for reference</remarks>
struct Segments {
	uint8_t A;
	uint8_t B;
	uint8_t C;
	uint8_t D;
	uint8_t E;
	uint8_t F;
	uint8_t G;
	uint8_t H;
};

class DigitDisplay {
private:
	//Defines the conversion between an ASCII character to a byte representing the segments that need to be lit on the display
	//The table encodes ASCII characters ranging from '0' (decimal 48) to 'Z' (decimal 90)
	//The table is zero based, therefore to obtain the segments byte for a particular supported character you need to take the decimal code of the character - 48
	//e.g.: the position for the 'A' character is 17 (65-48)
	//Anything outside the supported range will cause the display to go blank
	static const uint8_t ConversionTableLength = 43;
	static const uint8_t FirstSupportedCharacter = 48;
	static const uint8_t LastSupportedCharacter = FirstSupportedCharacter + ConversionTableLength - 1;
	static const uint8_t SegmentON = LOW;
	static const uint8_t SegmentOFF = HIGH;
	static const uint8_t ConversionTable[ConversionTableLength];

	Segments _segmentSetup;
public:
	DigitDisplay() {};
	DigitDisplay(Segments segmentSetup) :_segmentSetup(segmentSetup)
	{
		pinMode(_segmentSetup.A, OUTPUT);
		pinMode(_segmentSetup.B, OUTPUT);
		pinMode(_segmentSetup.C, OUTPUT);
		pinMode(_segmentSetup.D, OUTPUT);
		pinMode(_segmentSetup.E, OUTPUT);
		pinMode(_segmentSetup.F, OUTPUT);
		pinMode(_segmentSetup.G, OUTPUT);
		pinMode(_segmentSetup.H, OUTPUT);

		digitalWrite(_segmentSetup.A, HIGH);
		digitalWrite(_segmentSetup.B, HIGH);
		digitalWrite(_segmentSetup.C, HIGH);
		digitalWrite(_segmentSetup.D, HIGH);
		digitalWrite(_segmentSetup.E, HIGH);
		digitalWrite(_segmentSetup.F, HIGH);
		digitalWrite(_segmentSetup.G, HIGH);
		digitalWrite(_segmentSetup.H, HIGH);
	};
	virtual void Display(String text);
	virtual void Process();
protected:
	virtual void Display(String text, bool dpOn);
private:
	bool IsCharacterSupported(char character);
	uint8_t Convert(char character);
	bool IsBitSet(uint8_t bit, uint8_t byte);
};

#endif

