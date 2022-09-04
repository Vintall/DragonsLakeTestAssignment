#include "GameEngine.h"


void GameEngine::PreInit(int& width, int& height, bool& fullscreen)
{
	width = Window::GetInstance()->GetWidth();
	height = Window::GetInstance()->GetHeight();
	fullscreen = false;
}
bool GameEngine::Init()
{
	GameController::GetInstance();
	return true;
}

void GameEngine::Close()
{
	
}

bool GameEngine::Tick()
{
	Window::GetInstance()->DrawBackgroundSprite();
	GameWindow::GetInstance()->DrawBackgroundSprite();

	if (GameController::GetInstance()->game_state == GameController::GameState::InGame)
	{
		GameController::GetInstance()->CheckBallCollisions();
		GameController::GetInstance()->GetPlayer()->CheckAbilitiesTimer(getTickCount());

		GameMap::GetInstance()->DrawAllBricks();
		GameController::GetInstance()->GetPlayer()->GetPlatform()->DrawPlatform();
		GameController::GetInstance()->GetBall()->DrawBall();
	}

	Input::GetInstance()->InputTick();

	return false;
}

void GameEngine::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	Input::GetInstance()->OnMouseButtonMove(x, y);
}

void GameEngine::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (!isReleased)
		Input::GetInstance()->MouseButtonPressed(button);
	else
		Input::GetInstance()->MouseButtonReleased(button);
}

void GameEngine::onKeyPressed(FRKey k)
{
	Input::GetInstance()->KeyboardKeyPressed(k);
	
}

void GameEngine::onKeyReleased(FRKey k)
{
	Input::GetInstance()->KeyboardKeyReleased(k);
}

const char* GameEngine::GetTitle()
{
	return "Arkanoid";
}