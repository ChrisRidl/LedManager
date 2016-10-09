#ifndef LedManager_h
#define LedManager_h

class LedManager
{
	int _redPin;
	int _greenPin;
	int _bluePin;
	int _cycleDuration;
	bool _isInCycle;
	bool _bail;
	unsigned int _rgbColor[3] = {255, 0, 0};
	bool StopCycle();

	public:
		LedManager(int redPin, int greenPin, int bluePin, int cycleDuration);
		void SetColorRgb(unsigned int red, unsigned int green, unsigned int blue);
		bool Status();
		void TurnOffLeds();
		void CycleColors();
		void Initialize();
};

#endif