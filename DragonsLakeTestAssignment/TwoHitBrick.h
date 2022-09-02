#pragma once

#include "Brick.h"

class TwoHitBrick : public Brick
{
private:

public:
	void InstantiateBrick();
	void HitBrick();
	TwoHitBrick(int, int, float, float);
	void DrawBrick();
};