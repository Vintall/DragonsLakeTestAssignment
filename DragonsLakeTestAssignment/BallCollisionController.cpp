#include "BallCollisionController.h"

BallCollisionController* BallCollisionController::instance = nullptr;

BallCollisionController::BallCollisionController()
{

}

BallCollisionController* BallCollisionController::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BallCollisionController();
	}
	return instance;
}

void BallCollisionController::CheckForCollisions()
{
	float new_x = ball->GetXPos() + ball->GetXVectorSpeed() * ball->GetSpeed();
	float new_y = ball->GetYPos() + ball->GetYVectorSpeed() * ball->GetSpeed();
	float new_x_vec = ball->GetXVectorSpeed();
	float new_y_vec = ball->GetYVectorSpeed();

	CheckForBoundsCollisions(new_x, new_y, new_x_vec, new_y_vec);
	CheckForPlatformCollisions(new_x, new_y, new_x_vec, new_y_vec);
	CheckForBricksCollisions(new_x, new_y, new_x_vec, new_y_vec);

	ball->SetXPos(new_x);
	ball->SetYPos(new_y);
	ball->SetXVectorSpeed(new_x_vec);
	ball->SetYVectorSpeed(new_y_vec);
}
void BallCollisionController::CheckForBoundsCollisions(float& new_x, float& new_y, float& new_x_vec, float& new_y_vec)
{
	GameWindow* game_window = GameWindow::GetInstance();
	
	float distance_for_tick = sqrt((new_x - ball->GetXPos()) * (new_x - ball->GetXPos()) + (new_y - ball->GetYPos()) * (new_y - ball->GetYPos()));

	if (new_x + ball->GetRadius() > game_window->GetWidth())
	{
		new_x = game_window->GetWidth() - ball->GetRadius();
		new_x_vec *= -1;
	}
	if (new_x - ball->GetRadius() < 0)
	{
		new_x = ball->GetRadius();
		new_x_vec *= -1;
	}

	if (new_y + ball->GetRadius() > game_window->GetHeight()) // Loss condition
	{
		GameController::GetInstance()->GameOver(false);
		//new_y = game_window->GetHeight() - ball->GetRadius();
		//new_y_vec *= -1;
	}
	if (new_y - ball->GetRadius() < 0)
	{
		new_y = ball->GetRadius();
		new_y_vec *= -1;
	}
}
void BallCollisionController::CheckForBricksCollisions(float& new_x, float& new_y, float& new_x_vec, float& new_y_vec)
{
	GameWindow* game_window = GameWindow::GetInstance();

	std::vector<std::vector<Brick*>> map = GameMap::GetInstance()->GetMap();

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			float radius = ball->GetRadius();

			float x1 = map[i][j]->GetX() * map[i][j]->GetWidth();
			float x2 = x1 + map[i][j]->GetWidth();

			float y1 = map[i][j]->GetY() * map[i][j]->GetHeight();
			float y2 = y1 + map[i][j]->GetHeight();

			if (x1 <= new_x && new_x <= x2)
			{
				if (ball->GetYPos() + radius < y1 && new_y + radius >= y1)
				{
					new_y = y1 - radius;
					new_y_vec *= -1;
					if (map[i][j]->HitBrick())
					{
						GameController::GetInstance()->GetPlayer()->scores_without_touch++;
						GameController::GetInstance()->GetPlayer()->AddToScore(1);
						GameMap::GetInstance()->RemoveBrick(i, j);
					}
				}
				if (ball->GetYPos() - radius > y2 && new_y - radius <= y2)
				{
					new_y = y2 + radius;
					new_y_vec *= -1;
					if (map[i][j]->HitBrick())
					{
						GameController::GetInstance()->GetPlayer()->scores_without_touch++;
						GameController::GetInstance()->GetPlayer()->AddToScore(1);
						GameMap::GetInstance()->RemoveBrick(i, j);
					}
				}
			}
			if (y1 <= new_y && new_y <= y2)
			{
				if (ball->GetXPos() + radius < x1 && new_x + radius >= x1)
				{
					new_x = x1 - radius;
					new_x_vec *= -1;

					if (map[i][j]->HitBrick())
					{
						GameController::GetInstance()->GetPlayer()->scores_without_touch++;
						GameController::GetInstance()->GetPlayer()->AddToScore(1);
						GameMap::GetInstance()->RemoveBrick(i, j);
					}
				}
				if (ball->GetXPos() - radius > x2 && new_x - radius <= x2)
				{
					new_x = x2 + radius;
					new_x_vec *= -1;
					if (map[i][j]->HitBrick())
					{
						GameController::GetInstance()->GetPlayer()->scores_without_touch++;
						GameController::GetInstance()->GetPlayer()->AddToScore(1);
						GameMap::GetInstance()->RemoveBrick(i, j);
					}
				}
			}
			float x_dist;
			float y_dist;
			float overall_dist;
			if (new_x < x1)
			{
				x_dist = new_x - x1;

				if (new_y < y1) // Upper left corner
				{
					y_dist = new_y - y1;

					overall_dist = sqrt(x_dist * x_dist + y_dist * y_dist);
					
					if (overall_dist < radius)
					{
						//new_x = x1 - radius * new_x_vec;
						//new_y = y1 - radius * new_y_vec;
						
						new_x = ball->GetXPos();
						new_y = ball->GetYPos();

						new_x_vec = -ball->GetXVectorSpeed();
						new_y_vec = -ball->GetYVectorSpeed();


						if (map[i][j]->HitBrick())
						{
							GameController::GetInstance()->GetPlayer()->scores_without_touch++;
							GameController::GetInstance()->GetPlayer()->AddToScore(1);
							GameMap::GetInstance()->RemoveBrick(i, j);
						}
						//Collision
					}
				}
				if (new_y > y2) // Bottom left corner
				{
					y_dist = new_y - y2;

					overall_dist = sqrt(x_dist * x_dist + y_dist * y_dist);

					if (overall_dist < radius)
					{

						new_x = ball->GetXPos();
						new_y = ball->GetYPos();

						new_x_vec = -ball->GetXVectorSpeed();
						new_y_vec = -ball->GetYVectorSpeed();

						if (map[i][j]->HitBrick())
						{
							GameController::GetInstance()->GetPlayer()->scores_without_touch++;
							GameController::GetInstance()->GetPlayer()->AddToScore(1);
							GameMap::GetInstance()->RemoveBrick(i, j);
						}
						//Collision
					}
				}
			}
			if (new_x > x2)
			{
				x_dist = new_x - x2;

				if (new_y < y1) // Upper right corner
				{
					y_dist = new_y - y1;

					overall_dist = sqrt(x_dist * x_dist + y_dist * y_dist);

					if (overall_dist < radius)
					{

						new_x = ball->GetXPos();
						new_y = ball->GetYPos();

						new_x_vec = -ball->GetXVectorSpeed();
						new_y_vec = -ball->GetYVectorSpeed();

						if (map[i][j]->HitBrick())
						{
							GameController::GetInstance()->GetPlayer()->scores_without_touch++;
							GameController::GetInstance()->GetPlayer()->AddToScore(1);
							GameMap::GetInstance()->RemoveBrick(i, j);
						}
						//Collision
					}
				}
				if (new_y > y2) // Bottom right corner
				{
					y_dist = new_y - y2;

					overall_dist = sqrt(x_dist * x_dist + y_dist * y_dist);

					if (overall_dist < radius)
					{
						new_x = ball->GetXPos();
						new_y = ball->GetYPos();

						new_x_vec = -ball->GetXVectorSpeed();
						new_y_vec = -ball->GetYVectorSpeed();

						if (map[i][j]->HitBrick())
						{
							GameController::GetInstance()->GetPlayer()->scores_without_touch++;
							GameController::GetInstance()->GetPlayer()->AddToScore(1);
							GameMap::GetInstance()->RemoveBrick(i, j);
						}
						//Collision
					}
				}
			}

		}
	}
}
void BallCollisionController::CheckForPlatformCollisions(float& new_x, float& new_y, float& new_x_vec, float& new_y_vec)
{
	Platform* platform = GameController::GetInstance()->GetPlayer()->GetPlatform();
	if (new_x > platform->GetPos() - platform->GetWidth() / 2)
		if (new_x < platform->GetPos() + platform->GetWidth() / 2)
			if (ball->GetYPos() <= GameWindow::GetInstance()->GetHeight() * 0.9 && new_y > GameWindow::GetInstance()->GetHeight() * 0.9)
			{
				float shift_from_middle = (new_x - platform->GetPos()) / (platform->GetWidth() / 2);

				new_x_vec = abs(shift_from_middle) * shift_from_middle;
				new_y_vec = -sqrt(1 - shift_from_middle * shift_from_middle);
				GameController::GetInstance()->GetPlayer()->scores_without_touch = 0;
				new_y = GameWindow::GetInstance()->GetHeight() * 0.9;

				if (GameMap::GetInstance()->ready_for_game_over)
					GameController::GetInstance()->GameOver(true);
			}
}