#pragma once
#include "Platform.h"
#include <vector>
#include "Ability.h"
#include "SpeedDownAbility.h"
#include "SpeedUpAbility.h"
#include <random>

class Player
{
private:
	Platform* platform;
	int score = 0;
	std::vector<Ability*> abilities;
	int ability_cost = 20;
	int max_speed_up = 200; // %
	int max_speed_down = 50;

public:
	int scores_without_touch = 0;
	void InstantiatePlayer();
	Player();
	Platform* GetPlatform();
	void MoveLeft();
	void MoveRight();
	int GetScore();
	int SetScore(int);
	void AddToScore(int);
	bool AddAbility(int);
	bool CheckAbilitiesTimer(int);
	bool ResetSpeedModifier();
};