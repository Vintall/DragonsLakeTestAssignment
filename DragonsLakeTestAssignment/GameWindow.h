#pragma once
#include "Framework.h"
#include <string>
#include "SpriteHolder.h"
#include "Window.h"

class GameWindow
{
private:
	static GameWindow* instance;
	GameWindow();
public:
	static GameWindow* GetInstance();
	float GetWidth();
	float GetHeight();
	void DrawBackgroundSprite();
	float GetStartXPoint();
	float GetStartYPoint();

	float GetXLocalFromGlobal(float); // 800/1000 ->> 0.8
	float GetXGlobalFromLocal(float); // 0.8 ->> 800/1000

	float GetYLocalFromGlobal(float);
	float GetYGlobalFromLocal(float);
};