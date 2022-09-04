#include "Player.h"

void Player::InstantiatePlayer()
{

}
Player::Player()
{
	platform = new Platform();
}
Platform* Player::GetPlatform()
{
	return platform;
}
void Player::MoveLeft()
{
	platform->MoveLeft();
}
void Player::MoveRight()
{
	platform->MoveRight();
}
int Player::GetScore()
{
	return score;
}
void Player::AddToScore(int value)
{
	if (scores_without_touch < 3)
		score += value;
	else score += value * 3;

	std::cout << "Score: " << score << std::endl;
}
bool Player::AddAbility(int cur_time)
{
	if (score < 20)
	{
		std::cout << "Not enough score to buy ability!" << std::endl;
		return false;
	}

	SetScore(score - ability_cost);

	if (rand() % 2 == 0)
	{
		std::cout << "You bought Speed Up Ability!" << std::endl;
		abilities.push_back(new SpeedUpAbility(cur_time));
		ResetSpeedModifier();
	}
	else
	{
		std::cout << "You bought Speed Down Ability!" << std::endl;
		abilities.push_back(new SpeedDownAbility(cur_time));
		ResetSpeedModifier();
	}

	return true;
}
bool Player::CheckAbilitiesTimer(int cur_time)
{
	for (int i = 0; i < abilities.size(); i++)
		if (abilities[i]->IsEnd(cur_time))
		{
			abilities.erase(abilities.begin() + i);
			std::cout << "Ability was expired" << std::endl;
			ResetSpeedModifier();
		}

	return true;
}
int Player::SetScore(int new_score)
{
	score = new_score;

	std::cout << "Score: " << score << std::endl;

	return true;
}
bool Player::ResetSpeedModifier()
{
	float overall_speed_modifier = 100;
	for (int i = 0; i < abilities.size(); i++)
	{
		overall_speed_modifier += abilities[i]->GetAdditionalSpeed();
	}
	if (overall_speed_modifier < max_speed_down)
		overall_speed_modifier = max_speed_down;

	if (overall_speed_modifier > max_speed_up)
		overall_speed_modifier = max_speed_up;

	platform->speed_modifier = overall_speed_modifier;
	std::cout << "Overall Speed Modifier: " << overall_speed_modifier << "%" << std::endl;
	return true;
}