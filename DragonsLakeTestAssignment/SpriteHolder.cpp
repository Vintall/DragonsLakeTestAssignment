#include "SpriteHolder.h"

SpriteHolder* SpriteHolder::instance = nullptr;

SpriteHolder::SpriteHolder() {}

SpriteHolder* SpriteHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SpriteHolder();
		
	}
	return instance;
}
Sprite* SpriteHolder::GetWindowBackground()
{
	if (window_background == nullptr)
	{
		window_background = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + window_background_sprite_name).c_str());
		setSpriteSize(window_background, Window::GetInstance()->GetWidth(), Window::GetInstance()->GetHeight());
	}
	return window_background;
}
Sprite* SpriteHolder::GetGameWindowBackground()
{
	if (game_window_background == nullptr)
	{
		game_window_background = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + game_window_background_sprite_name).c_str());
		setSpriteSize(game_window_background, GameWindow::GetInstance()->GetWidth(), GameWindow::GetInstance()->GetHeight());
	}
	return game_window_background;
}
Sprite* SpriteHolder::GetOneHitBrick()
{
	if (one_hit_brick == nullptr)
	{
		one_hit_brick = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + one_hit_brick_sprite_name).c_str());
		setSpriteSize(one_hit_brick, GameWindow::GetInstance()->GetWidth() / 11, GameWindow::GetInstance()->GetWidth() / 33);
	}
	return one_hit_brick;
}
Sprite* SpriteHolder::GetTwoHitBrick1()
{
	if (two_hit_brick_1 == nullptr)
	{
		two_hit_brick_1 = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + two_hit_brick_sprite_name_1).c_str());
		setSpriteSize(two_hit_brick_1, GameWindow::GetInstance()->GetWidth() / 11, GameWindow::GetInstance()->GetWidth() / 33);
	}
	return two_hit_brick_1;
}
Sprite* SpriteHolder::GetTwoHitBrick2()
{
	if (two_hit_brick_2 == nullptr)
	{
		two_hit_brick_2 = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + two_hit_brick_sprite_name_2).c_str());
		setSpriteSize(two_hit_brick_2, GameWindow::GetInstance()->GetWidth() / 11, GameWindow::GetInstance()->GetWidth() / 33);
	}
	return two_hit_brick_2;
}
Sprite* SpriteHolder::GetUnbreakableBrick()
{
	if (unbreakable_brick == nullptr)
	{
		unbreakable_brick = createSprite((ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + unbreakable_brick_sprite_name).c_str());
		setSpriteSize(unbreakable_brick, GameWindow::GetInstance()->GetWidth() / 11, GameWindow::GetInstance()->GetWidth() / 33);
	}
	return unbreakable_brick;
}