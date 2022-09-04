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
std::string SpriteHolder::GetFullPath(std::string file_name)
{
	return ConsoleLineHandler::GetInstance()->GetApplicationPath() + std::string("data/") + file_name;
}
Sprite* SpriteHolder::GetWindowBackground()
{
	if (window_background == nullptr)
	{
		window_background = createSprite(GetFullPath(window_background_sprite_name).c_str());
		setSpriteSize(window_background, Window::GetInstance()->GetWidth(), Window::GetInstance()->GetHeight());
	}
	return window_background;
}
Sprite* SpriteHolder::GetGameWindowBackground()
{
	if (game_window_background == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();

		game_window_background = createSprite(GetFullPath(game_window_background_sprite_name).c_str());
		setSpriteSize(game_window_background, game_window->GetWidth(), game_window->GetHeight());
	}
	return game_window_background;
}
Sprite* SpriteHolder::GetOneHitBrick()
{
	if (one_hit_brick == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		one_hit_brick = createSprite(GetFullPath(one_hit_brick_sprite_name).c_str());
		setSpriteSize(one_hit_brick, game_window->GetWidth() / constants->MapWidth, game_window->GetWidth() / constants->MapWidth / constants->BrickRatio);
	}
	return one_hit_brick;
}
Sprite* SpriteHolder::GetTwoHitBrick1()
{
	if (two_hit_brick_1 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		two_hit_brick_1 = createSprite(GetFullPath(two_hit_brick_sprite_name_1).c_str());
		setSpriteSize(two_hit_brick_1, game_window->GetWidth() / constants->MapWidth, game_window->GetWidth() / constants->MapWidth / constants->BrickRatio);
	}
	return two_hit_brick_1;
}
Sprite* SpriteHolder::GetTwoHitBrick2()
{
	if (two_hit_brick_2 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		two_hit_brick_2 = createSprite(GetFullPath(two_hit_brick_sprite_name_2).c_str());
		setSpriteSize(two_hit_brick_2, game_window->GetWidth() / constants->MapWidth, game_window->GetWidth() / constants->MapWidth / constants->BrickRatio);
	}
	return two_hit_brick_2;
}
Sprite* SpriteHolder::GetUnbreakableBrick()
{
	if (unbreakable_brick == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		unbreakable_brick = createSprite(GetFullPath(unbreakable_brick_sprite_name).c_str());
		setSpriteSize(unbreakable_brick, game_window->GetWidth() / constants->MapWidth, game_window->GetWidth() / constants->MapWidth / constants->BrickRatio);
	}
	return unbreakable_brick;
}
Sprite* SpriteHolder::GetPlatform1()
{
	if (platform_1 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		platform_1 = createSprite(GetFullPath(platform_1_sprite_name).c_str());
		setSpriteSize(platform_1, game_window->GetWidth() / constants->PlatformBaseWidthDivider, game_window->GetWidth() / constants->PlatformBaseWidthDivider / constants->PlatformRatio);
	}
	return platform_1;
}
Sprite* SpriteHolder::GetPlatform2()
{
	if (platform_2 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		platform_2 = createSprite(GetFullPath(platform_2_sprite_name).c_str());
		setSpriteSize(platform_2, game_window->GetWidth() / constants->PlatformBaseWidthDivider, game_window->GetWidth() / constants->PlatformBaseWidthDivider / constants->PlatformRatio);
	}
	return platform_2;
}
Sprite* SpriteHolder::GetPlatform3()
{
	if (platform_3 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		platform_3 = createSprite(GetFullPath(platform_3_sprite_name).c_str());
		setSpriteSize(platform_3, game_window->GetWidth() / constants->PlatformBaseWidthDivider, game_window->GetWidth() / constants->PlatformBaseWidthDivider / constants->PlatformRatio);
	}
	return platform_3;
}
Sprite* SpriteHolder::GetBall1()
{
	if (ball_1 == nullptr)
	{
		GameWindow* game_window = GameWindow::GetInstance();
		ConstantsHolder* constants = ConstantsHolder::GetInstance();

		ball_1 = createSprite(GetFullPath(ball_1_sprite_name).c_str());
		setSpriteSize(ball_1, game_window->GetWidth() / constants->BallWidthDivider, game_window->GetWidth() / constants->BallWidthDivider);
	}
	return ball_1;
}