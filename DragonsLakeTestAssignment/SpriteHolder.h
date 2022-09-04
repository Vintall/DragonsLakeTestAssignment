#pragma once
#include <string>
#include "Framework.h"
#include "ConsoleLineHandler.h"
#include "GameWindow.h"
#include "Window.h"
#include "ConstantsHolder.h"


class SpriteHolder
{
private:
	static SpriteHolder* instance;
	const std::string window_background_sprite_name = "WindowBackgroundColor.png";
	const std::string game_window_background_sprite_name = "GameWindowBackgroundColor.png";
	const std::string one_hit_brick_sprite_name = "01-Breakout-Tiles.png";
	const std::string two_hit_brick_sprite_name_1 = "03-Breakout-Tiles.png";
	const std::string two_hit_brick_sprite_name_2 = "04-Breakout-Tiles.png";
	const std::string unbreakable_brick_sprite_name = "17-Breakout-Tiles.png";
	const std::string platform_1_sprite_name = "50-Breakout-Tiles.png";
	const std::string platform_2_sprite_name = "51-Breakout-Tiles.png";
	const std::string platform_3_sprite_name = "52-Breakout-Tiles.png";
	const std::string ball_1_sprite_name = "63-Breakout-Tiles.png";

	std::string GetFullPath(std::string);
	Sprite* window_background = nullptr;
	Sprite* game_window_background = nullptr;
	Sprite* one_hit_brick = nullptr;
	Sprite* two_hit_brick_1 = nullptr;
	Sprite* two_hit_brick_2 = nullptr;
	Sprite* unbreakable_brick = nullptr;
	Sprite* platform_1 = nullptr;
	Sprite* platform_2 = nullptr;
	Sprite* platform_3 = nullptr;
	Sprite* ball_1 = nullptr;
	SpriteHolder();
public:
	static SpriteHolder* GetInstance();
	Sprite* GetWindowBackground();
	Sprite* GetGameWindowBackground();
	Sprite* GetOneHitBrick();
	Sprite* GetTwoHitBrick1();
	Sprite* GetTwoHitBrick2();
	Sprite* GetUnbreakableBrick();
	Sprite* GetPlatform1();
	Sprite* GetPlatform2();
	Sprite* GetPlatform3();
	Sprite* GetBall1();
};