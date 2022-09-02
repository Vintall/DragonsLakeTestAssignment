#pragma once
#include <string>
#include "Framework.h"
#include "ConsoleLineHandler.h"
#include "GameWindow.h"
#include "Window.h"
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

	Sprite* window_background = nullptr;
	Sprite* game_window_background = nullptr;
	Sprite* one_hit_brick = nullptr;
	Sprite* two_hit_brick_1 = nullptr;
	Sprite* two_hit_brick_2 = nullptr;
	Sprite* unbreakable_brick = nullptr;
	SpriteHolder();
public:
	static SpriteHolder* GetInstance();
	Sprite* GetWindowBackground();
	Sprite* GetGameWindowBackground();
	Sprite* GetOneHitBrick();
	Sprite* GetTwoHitBrick1();
	Sprite* GetTwoHitBrick2();
	Sprite* GetUnbreakableBrick();
};