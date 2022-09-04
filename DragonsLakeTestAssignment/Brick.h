#pragma once
#include "Framework.h"
#include "SpriteHolder.h"
#include "Window.h"

class Brick
{
public:
	enum BrickType
	{
		Base,
		OneHit,
		TwoHit,
		Unbreakable
	};
protected:
	
	int hit_count;
	int x_pos; //In map slots
	int y_pos;
	float width;
	float height;
	bool is_destroyed = false;
	BrickType type = BrickType::Base;
public:
	
	BrickType GetType();
	Brick();
	~Brick();
	virtual bool HitBrick();
	virtual void DrawBrick();
	float GetWidth();
	float GetHeight();
	int GetX();
	int GetY();
};