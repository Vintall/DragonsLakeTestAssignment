#include "GameWindow.h"



GameWindow::GameWindow() {}

GameWindow* GameWindow::instance = nullptr;

GameWindow* GameWindow::GetInstance()
{
	if (instance == nullptr)
		instance = new GameWindow();
	return instance;
}

float GameWindow::GetWidth()
{
	if (Window::GetInstance()->GetWidth() >= Window::GetInstance()->GetHeight())
		return Window::GetInstance()->GetHeight() * ConstantsHolder::GetInstance()->GameWindowRatio;
	else
		return Window::GetInstance()->GetWidth();
}
float GameWindow::GetHeight()
{
	if (Window::GetInstance()->GetWidth() >= Window::GetInstance()->GetHeight())
		return Window::GetInstance()->GetHeight();
	else
		return Window::GetInstance()->GetWidth() / ConstantsHolder::GetInstance()->GameWindowRatio;
}
void GameWindow::DrawBackgroundSprite()
{
	drawSprite(SpriteHolder::GetInstance()->GetGameWindowBackground(), GetStartXPoint(), GetStartYPoint());
}
float GameWindow::GetStartXPoint()
{
	return Window::GetInstance()->GetWidth() / 2 - GetWidth() / 2;
}
float GameWindow::GetStartYPoint()
{
	return Window::GetInstance()->GetHeight() / 2 - GetHeight() / 2;
}

float GameWindow::GetXLocalFromGlobal(float x_global)
{
	return (x_global - GetStartXPoint()) / GetWidth();
}
float GameWindow::GetXGlobalFromLocal(float x_local)
{
	return x_local * GetWidth() + GetStartXPoint();
}
float GameWindow::GetYLocalFromGlobal(float y_global)
{
	return (y_global - GetStartYPoint()) / GetHeight();
}
float GameWindow::GetYGlobalFromLocal(float y_local)
{
	return y_local * GetHeight() + GetStartYPoint();
}
