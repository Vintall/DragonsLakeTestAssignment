#pragma once

#include "Brick.h"

class UnbreakableBrick : public Brick
{
private:

public:
	bool HitBrick();
	UnbreakableBrick(int, int, float, float);
	void DrawBrick();
};