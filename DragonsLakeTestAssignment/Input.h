#pragma once
#include "GameController.h"
#include "GameMap.h"
#include "Framework.h"

class Input
{
private:
	static Input* instance;
	Input();
	bool left_pressed = false;
	bool right_pressed = false;
	bool up_pressed = false;
	bool down_pressed = false;

	bool lmb_pressed = false; // Left   Mouse Button
	bool rmb_pressed = false; // Right  Mouse Button
	bool mmb_pressed = false; // Middle Mouse Button

	int mouse_x = 0;
	int mouse_y = 0;

	bool can_launch_ball = true;
public:
	static Input* GetInstance();
	
	void KeyboardKeyPressed(FRKey);
	void KeyboardKeyReleased(FRKey);

	void MouseButtonPressed(FRMouseButton);
	void MouseButtonReleased(FRMouseButton);

	void OnMouseButtonMove(int, int);
	
	void InputTick();

	void LaunchBall();

	void RestartBallInput();
};