#pragma once

#include "Brick.h"

class UnbreakableBrick : public Brick
{
private:

public:
	void InstantiateBrick();
	void HitBrick();
	UnbreakableBrick(int, int, float, float);
	void DrawBrick();
};