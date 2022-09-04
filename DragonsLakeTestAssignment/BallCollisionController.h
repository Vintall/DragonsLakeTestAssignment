#pragma once
#include "Ball.h"
#include "GameController.h"
#include "GameMap.h"

class BallCollisionController
{
private:
	static BallCollisionController* instance;
	BallCollisionController();
public:
	Ball* ball;
	static BallCollisionController* GetInstance();
	void CheckForCollisions();
	void CheckForBoundsCollisions(float&, float&, float&, float&);
	void CheckForBricksCollisions(float&, float&, float&, float&);
	void CheckForPlatformCollisions(float&, float&, float&, float&);
};