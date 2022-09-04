#include "GameController.h"

GameController* GameController::instance = nullptr;

GameController* GameController::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameController();
	}
	return instance;
}
GameController::GameController()
{
	InstantiateGame();
}

Player* GameController::GetPlayer()
{	//can not be nullptr
	return player;
}
Ball* GameController::GetBall()
{
	return ball;
}
void GameController::CheckBallCollisions()
{
	if (BallCollisionController::GetInstance()->ball == nullptr)
		BallCollisionController::GetInstance()->ball = ball;

	BallCollisionController::GetInstance()->CheckForCollisions();

	GameMap::GetInstance()->CheckForGameOverCondition();
		
}
void GameController::LaunchBall(int x, int y)
{
	float x_rel = x - GameWindow::GetInstance()->GetStartXPoint() - ball->GetXPos();
	float y_rel = y - GameWindow::GetInstance()->GetStartYPoint() - ball->GetYPos();

	float vec_magn = sqrt(x_rel * x_rel + y_rel * y_rel);

	ball->SetXVectorSpeed(x_rel / vec_magn);
	ball->SetYVectorSpeed(y_rel / vec_magn);
}
void GameController::GameOver(bool is_win)
{
	if (is_win)
	{
		game_state = GameState::Win;
		std::cout << "Victory" << std::endl;
	}
	else
	{
		game_state = GameState::Loss;
		std::cout << "You lost" << std::endl;
	}
	std::cout << "Press Up Arrow to restart!" << std::endl;
	//InstantiateGame();
}
void GameController::InstantiateGame()
{
	delete(player);
	delete(ball);

	player = new Player();
	ball = new Ball();
	GameMap::GetInstance()->InstantiateMap();
	Input::GetInstance()->RestartBallInput();
	BallCollisionController::GetInstance()->ball = ball;

	game_state = GameState::InGame;
}