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
	int random_map = rand() % 3;
	if (random_map == 0)
		InstantiateMap1();
	else if (random_map == 1)
		InstantiateMap2();
	else
		InstantiateMap3();
	
}
void GameMap::InstantiateMap1()
{
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

			if (j % 3 == 0)
				map[i][j] = new UnbreakableBrick(j, i, brick_width, brick_height);
			else
			{

				if (brick_id == 0 || brick_id == 1)
					map[i][j] = new OneHitBrick(j, i, brick_width, brick_height);

				if (brick_id == 2 || brick_id == 3)
					map[i][j] = new TwoHitBrick(j, i, brick_width, brick_height);

				//if (brick_id == 4)
				//	map[i][j] = new UnbreakableBrick(j, i, brick_width, brick_height);



				brick_id++;
				if (brick_id == 4)
					brick_id = 0;

			}
		}
	}
}
void GameMap::InstantiateMap2()
{
	ConstantsHolder* constants = ConstantsHolder::GetInstance();

	map = std::vector<std::vector<Brick*>>(7);
	int brick_id = 0;
	for (int i = 0; i < 7; i++)
	{
		map[i] = std::vector<Brick*>(7);
		for (int j = 0; j < 7; j++)
		{
			float brick_width = 1. * GameWindow::GetInstance()->GetWidth() / constants->MapWidth;
			float brick_height = brick_width / constants->BrickRatio;

			if (brick_id == 0)
				map[i][j] = new OneHitBrick(j+2, i+6, brick_width, brick_height);

			if (brick_id == 1)
				map[i][j] = new TwoHitBrick(j+2, i+6, brick_width, brick_height);


			brick_id++;
			if (brick_id == 2)
				brick_id = 0;
		}
	}
}
void GameMap::InstantiateMap3()
{
	ConstantsHolder* constants = ConstantsHolder::GetInstance();

	map = std::vector<std::vector<Brick*>>(7);
	int brick_id = 0;
	for (int i = 0; i < 7; i++)
	{
		int l_widtd = constants->MapWidth;
		if(i!=6)
		map[i] = std::vector<Brick*>(l_widtd);
		else
		{
			l_widtd = (constants->MapWidth + 1) / 2;
			map[i] = std::vector<Brick*>(l_widtd);
		}
		for (int j = 0; j < l_widtd; j++)
		{
			float brick_width = 1. * GameWindow::GetInstance()->GetWidth() / constants->MapWidth;
			float brick_height = brick_width / constants->BrickRatio;

			if (i == 6)
			{
				map[i][j] = new UnbreakableBrick(j*2, i + 10, brick_width, brick_height);
			}
			else
			{
				if (rand() % 2 == 0)
				{
					map[i][j] = new OneHitBrick(j, i + 2, brick_width, brick_height);
				}
				else
				{
					map[i][j] = new TwoHitBrick(j, i + 2, brick_width, brick_height);
				}
			}
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