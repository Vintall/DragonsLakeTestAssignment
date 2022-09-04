#include "OneHitBrick.h"

OneHitBrick::OneHitBrick(int x, int y, float width, float height)
{
	x_pos = x;
	y_pos = y;
	this->width = width;
	this->height = height;
	hit_count = 1;
	type = BrickType::OneHit;
}

void OneHitBrick::DrawBrick()
{
	GameWindow* game_window = GameWindow::GetInstance();
    
	drawSprite(SpriteHolder::GetInstance()->GetOneHitBrick(),
		game_window->GetStartXPoint() + x_pos * width,
		game_window->GetStartYPoint() + y_pos * height);
}
bool OneHitBrick::HitBrick()
{
	is_destroyed = true;
	return true; // true, if destroyed
}