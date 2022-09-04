#include "Input.h"

Input* Input::instance = nullptr;

Input* Input::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Input();
	}
	return instance;
}
Input::Input()
{

}
void Input::KeyboardKeyPressed(FRKey key)
{
	switch (key)
	{
	case FRKey::LEFT:
		left_pressed = true;
		break;

	case FRKey::RIGHT:
		right_pressed = true;
		break;

	case FRKey::UP:
		up_pressed = true;
		break;

	case FRKey::DOWN:
		down_pressed = true;
		break;

	default:
		break;
	}
}
void Input::KeyboardKeyReleased(FRKey key)
{
	switch (key)
	{
	case FRKey::LEFT:
		left_pressed = false;
		break;

	case FRKey::RIGHT:
		right_pressed = false;
		break;

	case FRKey::UP:
		up_pressed = false;
		
		if (GameController::GetInstance()->game_state == GameController::GameState::Loss ||
			GameController::GetInstance()->game_state == GameController::GameState::Win)
		{
			GameController::GetInstance()->InstantiateGame();
		}

		break;

	case FRKey::DOWN:
		down_pressed = false;
		break;

	default:
		break;
	}
}
void Input::MouseButtonPressed(FRMouseButton key)
{
	switch (key)
	{
	case FRMouseButton::LEFT:
		lmb_pressed = true;


		break;

	case FRMouseButton::RIGHT:
		rmb_pressed = true;
		break;

	case FRMouseButton::MIDDLE:
		mmb_pressed = true;
		break;

	default:
		break;
	}
}
void Input::MouseButtonReleased(FRMouseButton key)
{
	switch (key)
	{
	case FRMouseButton::LEFT:
		lmb_pressed = false;

		if (GameController::GetInstance()->game_state == GameController::GameState::InGame)
		{
			if (can_launch_ball)
			{
				can_launch_ball = false;
				LaunchBall();
			}
		}

		break;

	case FRMouseButton::RIGHT:
		rmb_pressed = false;
		if (GameController::GetInstance()->game_state == GameController::GameState::InGame)
		{
			GameController::GetInstance()->GetPlayer()->AddAbility(getTickCount());
		}
		break;

	case FRMouseButton::MIDDLE:
		mmb_pressed = false;
		break;

	default:
		break;
	}
}
void Input::OnMouseButtonMove(int x, int y)
{
	mouse_x = x;
	mouse_y = y;
}
void Input::InputTick()
{
	if (GameController::GetInstance()->game_state == GameController::GameState::InGame)
	{
		if (left_pressed)
			GameController::GetInstance()->GetPlayer()->MoveLeft();

		if (right_pressed)
			GameController::GetInstance()->GetPlayer()->MoveRight();
	}
}
void Input::LaunchBall()
{
	GameController::GetInstance()->LaunchBall(mouse_x, mouse_y);
}
void Input::RestartBallInput()
{
	can_launch_ball = true;
}