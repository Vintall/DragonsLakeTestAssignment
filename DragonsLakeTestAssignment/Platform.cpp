#include "Platform.h"

Platform::Platform()
{
	pos = GameWindow::GetInstance()->GetWidth() / 2;
	speed = 1.;  // Tick sensitive!!
	width = GameWindow::GetInstance()->GetWidth() / ConstantsHolder::GetInstance()->PlatformBaseWidthDivider;
	
	animation_index = 0;
}
Platform::~Platform()
{

}
void Platform::DrawPlatform()
{
	GameWindow* game_window = GameWindow::GetInstance();

	if (animation_index < 30)
		drawSprite(SpriteHolder::GetInstance()->GetPlatform1(),
			game_window->GetStartXPoint() + pos - width / 2,
			game_window->GetYGlobalFromLocal(0.9));
	else
	if (animation_index < 60)
		drawSprite(SpriteHolder::GetInstance()->GetPlatform2(),
			game_window->GetStartXPoint() + pos - width / 2,
			game_window->GetYGlobalFromLocal(0.9));
	else
	if (animation_index < 90)
		drawSprite(SpriteHolder::GetInstance()->GetPlatform3(),
			game_window->GetStartXPoint() + pos - width / 2,
			game_window->GetYGlobalFromLocal(0.9));

	if (++animation_index == 90)
		animation_index = 0;
}
void Platform::MoveLeft()
{
	GameWindow* game_window = GameWindow::GetInstance();
	pos -= speed * speed_modifier / 100;
	if (pos - width / 2 < 0)
		pos = width / 2;
}
void Platform::MoveRight()
{
	GameWindow* game_window = GameWindow::GetInstance();
	pos += speed * speed_modifier / 100;
	if (pos + width / 2 > game_window->GetWidth())
		pos = game_window->GetWidth() - width / 2;
}
float Platform::GetWidth()
{
	return width;
}
float Platform::GetPos()
{
	return pos;
}