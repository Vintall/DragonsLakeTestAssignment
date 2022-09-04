#pragma once
#include "Framework.h"
#include "SpriteHolder.h"
#include "GameWindow.h"
#include "ConstantsHolder.h"

class Platform
{
private:
	float width;
	float pos;
	float speed; //in seconds
	int animation_index;
public:
	float speed_modifier = 100;
	Platform();
	~Platform();
	void DrawPlatform();
	void MoveLeft();
	void MoveRight();
	float GetPos();
	float GetWidth();
};
