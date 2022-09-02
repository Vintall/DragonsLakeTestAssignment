#include "Window.h"

Window* Window::instance = 0;

Window* Window::GetInstance()
{
	if (instance == 0)
		instance = new Window();

	return instance;
}
void Window::SetWindow(int width, int height)
{
	this->width = width;
	this->height = height;
	was_set = true;
}
int Window::GetWidth()
{
	if (!was_set)
		SetDefaultWindow();

	return width;
}
int Window::GetHeight()
{
	if (!was_set)
		SetDefaultWindow();

	return height;
}
void Window::SetDefaultWindow()
{
	SetWindow(default_width, default_height);
}

Window::Window() 
{
}
void Window::DrawBackgroundSprite()
{
	drawSprite(SpriteHolder::GetInstance()->GetWindowBackground(), 0, 0);
}
