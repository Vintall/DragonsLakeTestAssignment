#include "GameEngine.h"
#include <iostream>
#include "Window.h"
#include "GameWindow.h"
#include <string>
#include "ConsoleLineHandler.h"
#include "GameMap.h"

void GameEngine::PreInit(int& width, int& height, bool& fullscreen)
{
	width = Window::GetInstance()->GetWidth();
	height = Window::GetInstance()->GetHeight();
	fullscreen = false;
}
bool GameEngine::Init()
{
	return true;
}

void GameEngine::Close()
{

}

bool GameEngine::Tick()
{
	Window::GetInstance()->DrawBackgroundSprite();
	GameWindow::GetInstance()->DrawBackgroundSprite();
	GameMap::GetInstance()->DrawAllBricks();
	return false;
}

void GameEngine::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	system("cls");
	std::cout << x << "   " << y << "         " << xrelative << "   " << yrelative;
}

void GameEngine::onMouseButtonClick(FRMouseButton button, bool isReleased)
{

}

void GameEngine::onKeyPressed(FRKey k)
{
	if (k == FRKey::LEFT)
	{
		std::cout << "Left" << std::endl;
	}
	if (k == FRKey::RIGHT)
	{
		std::cout << "Right" << std::endl;
	}
}

void GameEngine::onKeyReleased(FRKey k)
{

}

const char* GameEngine::GetTitle()
{
	return "Arkanoid";
}