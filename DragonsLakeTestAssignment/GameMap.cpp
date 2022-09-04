#include "GameMap.h"

GameMap::GameMap() 
{
	InstantiateMap();
}
void GameMap::InstantiateMap()
{
	if (map.size() != 0)
	{
		map.clear();
	}

	ConstantsHolder* constants = ConstantsHolder::GetInstance();

	map = std::vector<std::vector<Brick*>>(constants->MapHeight);
	int brick_id = 0;
	for (int i = 0; i < constants->MapHeight; i++)
	{
		map[i] = std::vector<Brick*>(constants->MapWidth);
		for (int j = 0; j < constants->MapWidth; j++)
		{
			float brick_width = 1. * GameWindow::GetInstance()->GetWidth() / constants->MapWidth;
			float brick_height = brick_width / constants->BrickRatio;

			if (brick_id == 0 || brick_id == 1)
				map[i][j] = new OneHitBrick(j, i, brick_width, brick_height);

			if (brick_id == 2 || brick_id == 3)
				map[i][j] = new TwoHitBrick(j, i, brick_width, brick_height);

			if (brick_id == 4)
				map[i][j] = new UnbreakableBrick(j, i, brick_width, brick_height);

			brick_id++;
			if (brick_id == 5)
				brick_id = 0;
		}
	}
	
}
int GameMap::GetWidth()
{
	return ConstantsHolder::GetInstance()->MapWidth;
}
int GameMap::GetHeight()
{
	return ConstantsHolder::GetInstance()->MapHeight;
}

GameMap* GameMap::instance = nullptr;
GameMap* GameMap::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameMap();
	}
	return instance;
}
void GameMap::DrawAllBricks()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == nullptr)
				continue;

			map[i][j]->DrawBrick();
		}
	}
}
const std::vector<std::vector<Brick*>>& GameMap::GetMap()
{
	return map;
}
void GameMap::RemoveBrick(int i, int j)
{
	Brick* to_destroy = map[i][j];
	map[i].erase(map[i].begin() + j);
	delete(to_destroy);
}
void GameMap::CheckForGameOverCondition()
{
	bool is_game_over = true;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j]->GetType() != Brick::BrickType::Unbreakable)
			{
				is_game_over = false;
				i = map.size();
				break;
			}
		}
	}
	ready_for_game_over = is_game_over;
}