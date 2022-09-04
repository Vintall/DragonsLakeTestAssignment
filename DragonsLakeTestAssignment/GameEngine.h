#pragma once

#include "Framework.h"
#include "GameController.h"
#include <iostream>
#include "Window.h"
#include "GameWindow.h"
#include <string>
#include "ConsoleLineHandler.h"
#include "GameMap.h"
#include "Input.h"

class GameEngine : public Framework
{

public:
	
	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();

	virtual void Close();

	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

	virtual const char* GetTitle() override;
};