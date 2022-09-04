#include "UnbreakableBrick.h"

UnbreakableBrick::UnbreakableBrick(int x, int y, float width, float height)
{
	x_pos = x;
	y_pos = y;
	this->width = width;
	this->height = height;
	type = BrickType::Unbreakable;
}

void UnbreakableBrick::DrawBrick()
{
	GameWindow* game_window = GameWindow::GetInstance();

	drawSprite(SpriteHolder::GetInstance()->GetUnbreakableBrick(),
		game_window->GetStartXPoint() + x_pos * width,
		game_window->GetStartYPoint() + y_pos * height);
}
bool UnbreakableBrick::HitBrick()
{
	return false;
}