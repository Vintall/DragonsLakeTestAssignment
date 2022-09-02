#include "GameMap.h"

GameMap::GameMap() 
{
	map = new Brick ** [height];
	int fdas = 0;
	for (int i = 0; i < height; i++)
	{
		map[i] = new Brick*[width];

		for (int j = 0; j < width; j++)
		{
			if (fdas == 0)
				map[i][j] = new OneHitBrick(j, i, 1. * GameWindow::GetInstance()->GetWidth() / width, GameWindow::GetInstance()->GetWidth() / width / brick_ratio);

			if (fdas == 1)
				map[i][j] = new TwoHitBrick(j, i, 1. * GameWindow::GetInstance()->GetWidth() / width, GameWindow::GetInstance()->GetWidth() / width / brick_ratio);

			if (fdas == 2)
				map[i][j] = new UnbreakableBrick(j, i, 1. * GameWindow::GetInstance()->GetWidth() / width, GameWindow::GetInstance()->GetWidth() / width / brick_ratio);

			fdas++;
			if (fdas == 3)
				fdas = 0;
		}
	}
}

int GameMap::GetWidth()
{
	return width;
}
int GameMap::GetHeight()
{
	return height;
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
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Brick fdas = *map[i][j];
			//OneHitBrick fds = (OneHitBrick)map[i][j];
			map[i][j]->DrawBrick();
		}
	}
}