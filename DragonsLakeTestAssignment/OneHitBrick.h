#pragma once

#include "Brick.h"



class OneHitBrick : public Brick
{
private:
public:
	OneHitBrick(int, int, float, float); //width on map, height on map
	void DrawBrick();
};
