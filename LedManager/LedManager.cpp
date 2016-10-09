// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "LedManager.h"

LedManager::LedManager(int redPin, int greenPin, int bluePin, int cycleDuration)
{
	_isInCycle = false;
	_bail = false;
	// _rgbColor[3] = {255, 0, 0};
	_redPin = redPin;
	_greenPin = greenPin;
	_bluePin = bluePin;
	_cycleDuration = cycleDuration;
}


void LedManager::SetColorRgb(unsigned int red, unsigned int green, unsigned int blue)
{
	analogWrite(_redPin, red);
    analogWrite(_greenPin, green);
    analogWrite(_bluePin, blue);
}

void LedManager::CycleColors()
{
	_isInCycle = true;
	Serial.println("Dark");
	_rgbColor[0] = 0;
	_rgbColor[1] = 0;
	_rgbColor[2] = 0;
	SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
	delay(_cycleDuration);

	// Off to Red
	Serial.println("Going Red");
	for(int i = 0; i < 255; i += 1) 
	{
		_rgbColor[0] = i;
		
		SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
		delay(_cycleDuration);
	}
		Serial.println("Going Orange");
		// Red to Orange/Yellow
		for(int i = 0; i < 255; i += 1) 
		{
			_rgbColor[1] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}

		Serial.println("Going Green");
		//Orange/yellow to Green
		for(int i = 255; i >= 0; i -= 1) 
		{
			_rgbColor[0] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}
		Serial.println("Going Torquoise");
		// Green to Torquoise
		for(int i = 0; i < 255; i += 1) 
		{
			_rgbColor[2] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}
		Serial.println("Going Blue");
		// Turquoise to Blue
		for(int i = 255; i >= 0; i -= 1) 
		{
			_rgbColor[1] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}
		Serial.println("Going Violet");
		// Blue to Voilet
		for(int i = 0; i < 255; i += 1) 
		{
			_rgbColor[0] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}
		Serial.println("Going red");
		// Voilet to Red
		for(int i = 255; i >= 0; i -= 1) 
		{
			_rgbColor[2] = i;
			
			SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
			delay(_cycleDuration);
		}

	TurnOffLeds();	
}
// void LedManager::CycleColors()
//   {
//     for (int deccolor = 0; deccolor < 3; deccolor += 1) {
//         int inccolor = deccolor == 2 ? 0 : deccolor + 1;
// 		if (_bail)
// 			{
// 				StopCycle();
// 				return;
// 			}
//           // cross-fade the two colors.
//           for(int i = 0; i < 255; i += 1) {
// 			if (_bail)
// 			{
// 				StopCycle();
// 				return;
// 			}
//             _rgbColor[deccolor] -= 1;
//             _rgbColor[inccolor] += 1;
            
//             SetColorRgb((unsigned int)_rgbColor[0], (unsigned int)_rgbColor[1], (unsigned int)_rgbColor[2]);
//             delay(_cycleDuration);
//           }
//         }
// }

bool LedManager::StopCycle()
{
	_bail = false;
}

bool LedManager::Status()
{
	return _isInCycle;
}

void LedManager::TurnOffLeds()
{
	// if (_isInCycle)
	// {
	// 	_bail = true;
	// }
	// else 
	// {
	// 	return;
	// }

	// while(_bail)
	// {
	// 	delay(1000);
	// 	Serial.println("waiting for light cycle to finish...");
	// }
	SetColorRgb(0, 0, 0);
	// for(int i = 255; i >= 0; i--)
	// {
	// 	SetColorRgb(_rgbColor[0], _rgbColor[1], _rgbColor[2]);
    // 	delay(30);
	// }
	
	_isInCycle = false;
}


void LedManager::Initialize()
{
	Serial.println("Initializing");
	pinMode(_redPin, OUTPUT);
	pinMode(_greenPin, OUTPUT);
	pinMode(_bluePin, OUTPUT);

	for(int i = 0; i < 5; i++){	
		SetColorRgb(127,127,0);
		delay(500);
		SetColorRgb(0,0,0);
		delay(500);
	}
}
