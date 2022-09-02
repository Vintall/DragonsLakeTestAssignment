#pragma once
#include "Brick.h"
#include "OneHitBrick.h"
#include "TwoHitBrick.h"
#include "UnbreakableBrick.h"
class GameMap
{
private:
	static GameMap* instance;
	const int width = 11;
	const int height = 22;
	const float brick_ratio = 3; //  width/height 
	Brick*** map;
	GameMap();
public:
	int GetWidth();
	int GetHeight();
	static GameMap* GetInstance();
	void DrawAllBricks();
};