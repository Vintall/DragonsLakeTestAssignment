#include "GameWindow.h"
#include "Window.h"


GameWindow::GameWindow() {}

GameWindow* GameWindow::instance = nullptr;

GameWindow* GameWindow::GetInstance()
{
	if (instance == nullptr)
		instance = new GameWindow();
	return instance;
}

int GameWindow::GetWidth()
{
	if (width != -1)
		return width;

	if (Window::GetInstance()->GetWidth() >= Window::GetInstance()->GetHeight())
		return Window::GetInstance()->GetHeight() * GameWindowRatio;
	else
		return Window::GetInstance()->GetWidth();
}
int GameWindow::GetHeight()
{
	if (height != -1)
		return height;

	if (Window::GetInstance()->GetWidth() >= Window::GetInstance()->GetHeight())
		return Window::GetInstance()->GetHeight();
	else
		return Window::GetInstance()->GetWidth() / GameWindowRatio;
}
void GameWindow::ResetWindow()
{
	width = -1;
	height = -1;
}
void GameWindow::DrawBackgroundSprite()
{
	drawSprite(SpriteHolder::GetInstance()->GetGameWindowBackground(), GetStartXPoint(), GetStartYPoint());
}
int GameWindow::GetStartXPoint()
{
	return Window::GetInstance()->GetWidth() / 2 - GetWidth() / 2;
}
int GameWindow::GetStartYPoint()
{
	return Window::GetInstance()->GetHeight() / 2 - GetHeight() / 2;
}