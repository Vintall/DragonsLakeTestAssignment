#pragma once

class ConstantsHolder
{
private:
	static ConstantsHolder* instance;
	ConstantsHolder();
public:
	static ConstantsHolder* GetInstance();
	const int MapWidth = 11;
	const int MapHeight = 22;
	const int BrickRatio = 3;  // width divide by height
	const int PlatformRatio = 3.79;
	const float PlatformBaseWidthDivider = MapWidth / 2;
	const float BallWidthDivider = MapWidth * 4;
	const double GameWindowRatio = 0.7; // Ratio = Width/Height (800/600=1.6)       //Preventing game from shrinking, if we break resolution ratio
};
