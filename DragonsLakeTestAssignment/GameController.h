#pragma once
#include "Player.h"
#include "Ball.h"
#include "BallCollisionController.h"
#include "Input.h"


class GameController
{
private:
	static GameController* instance;
	Player* player;
	Ball* ball;
	GameController();
	bool ball_can_be_launched = true;
public:
	enum GameState
	{
		Win,
		Loss,
		InGame,
		PreGame
	};
	GameState game_state = GameState::PreGame;
	static GameController* GetInstance();
	Player* GetPlayer();
	Ball* GetBall();
	void CheckBallCollisions();
	void LaunchBall(int, int);
	void GameStart();
	void GameOver(bool);
	void InstantiateGame();
};