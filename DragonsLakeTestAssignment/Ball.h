#pragma once
#include "GameWindow.h"




class Ball
{
private:
	float radius;
	float x_pos = 0;
	float y_pos = 0;
	float speed = 1. / 1;
	float x_vector_speed = 0;
	float y_vector_speed = 0;
	
public:
	Ball();
	~Ball();
	void DrawBall();
	void BallMovement();
	float GetXPos();
	float GetYPos();
	float GetSpeed();
	float GetXVectorSpeed();
	float GetYVectorSpeed();
	float GetRadius();

	void SetRadius(float);
	void SetXPos(float);
	void SetYPos(float);
	void SetSpeed(float);
	void SetXVectorSpeed(float);
	void SetYVectorSpeed(float);
};