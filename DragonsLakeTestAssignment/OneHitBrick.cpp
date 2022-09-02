#include "OneHitBrick.h"

OneHitBrick::OneHitBrick(int x, int y, float width, float height)
{
	x_pos = x;
	y_pos = y;
	this->width = width;
	this->height = height;
}

void OneHitBrick::DrawBrick()
{
	GameWindow* game_window = GameWindow::GetInstance();
    
	drawSprite(SpriteHolder::GetInstance()->GetOneHitBrick(),
		game_window->GetStartXPoint() + x_pos * width,
		game_window->GetStartYPoint() + y_pos * height);
}