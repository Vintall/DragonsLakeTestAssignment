#pragma once
#include <string>
#include <Framework.h>
#include "ConsoleLineHandler.h"
#include "SpriteHolder.h"
class Window
{
private:
	const int default_width = 800; // Default size of window
	const int default_height = 600;
	int width; // Size of outer rectangle, which represented by window size. Contains inner rectangle
	int height;
	bool was_set = 0;
	static Window* instance; // Singleton
	Window();
public:
	void SetWindow(int width, int height);
	void SetDefaultWindow();
	static Window* GetInstance();
	int GetWidth();
	int GetHeight();
	void DrawBackgroundSprite();
};