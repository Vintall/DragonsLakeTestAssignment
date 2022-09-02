#pragma once

#include "Framework.h"
#include "SpriteHolder.h"
#include "Window.h"

class Brick
{
protected:
	int hit_count;
	int x_pos; //In map slots
	int y_pos;
	float width;
	float height;

public:
	Brick();
	~Brick();
	virtual void HitBrick();
	virtual void InstantiateBrick();
	virtual void DrawBrick();
};