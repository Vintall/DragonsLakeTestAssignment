#pragma once
#include "Framework.h"
#include <string>
#include "SpriteHolder.h"
class GameWindow
{
private:
	static GameWindow* instance;
	const double GameWindowRatio = 1; // Ratio = Width/Height (800/600=1.6)       //Preventing game from shrinking, if we break resolution ratio
	int width = -1;
	int height = -1;
	GameWindow();
public:
	static GameWindow* GetInstance();
	int GetWidth();
	int GetHeight();
	void ResetWindow();
	void DrawBackgroundSprite();
	int GetStartXPoint();
	int GetStartYPoint();
};