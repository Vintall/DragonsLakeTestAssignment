#pragma once

#include "Brick.h"

class TwoHitBrick : public Brick
{
private:

public:
	bool HitBrick();
	TwoHitBrick(int, int, float, float);
	void DrawBrick();
};