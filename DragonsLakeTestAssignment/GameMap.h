#pragma once
#include "Brick.h"
#include "OneHitBrick.h"
#include "TwoHitBrick.h"
#include "UnbreakableBrick.h"
#include <vector>
#include "ConstantsHolder.h"

class GameMap
{
private:
	static GameMap* instance;
	std::vector<std::vector<Brick*>> map;
	GameMap();
public:
	int GetWidth();
	int GetHeight();
	static GameMap* GetInstance();
	void DrawAllBricks();
	const std::vector<std::vector<Brick*>>& GetMap();
	void RemoveBrick(int, int);
	void CheckForGameOverCondition();
	void InstantiateMap();

	bool ready_for_game_over = false;
};