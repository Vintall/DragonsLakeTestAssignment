#include "TwoHitBrick.h"

void TwoHitBrick::InstantiateBrick()
{
	hit_count = 2;
}
void TwoHitBrick::HitBrick()
{
	hit_count--;

	if (hit_count == 0) 
	{
		//remove_brick
	}
		
}
TwoHitBrick::TwoHitBrick(int x, int y, float width, float height)
{
	x_pos = x;
	y_pos = y;
	this->width = width;
	this->height = height;
	hit_count = 2;
}
void TwoHitBrick::DrawBrick()
{
	GameWindow* game_window = GameWindow::GetInstance();

	if (hit_count == 2)
	{
		drawSprite(SpriteHolder::GetInstance()->GetTwoHitBrick1(),
			game_window->GetStartXPoint() + x_pos * width,
			game_window->GetStartYPoint() + y_pos * height);
	}
	if (hit_count == 1)
	{
		drawSprite(SpriteHolder::GetInstance()->GetTwoHitBrick2(),
			game_window->GetStartXPoint() + x_pos * width,
			game_window->GetStartYPoint() + y_pos * height);
	}
}