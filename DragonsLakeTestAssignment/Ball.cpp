#include "Ball.h"

Ball::Ball()
{
	GameWindow* game_window = GameWindow::GetInstance();
	radius = game_window->GetWidth() / ConstantsHolder::GetInstance()->BallWidthDivider / 2;
	x_pos = game_window->GetWidth() / 2;
	y_pos = game_window->GetHeight() * 0.8;
}
Ball::~Ball()
{

}
void Ball::DrawBall()
{
	GameWindow* game_window = GameWindow::GetInstance();

	drawSprite(SpriteHolder::GetInstance()->GetBall1(),
		game_window->GetStartXPoint() + x_pos - radius,
		game_window->GetStartYPoint() + y_pos - radius);
}
void Ball::BallMovement()
{
}
float Ball::GetXPos()
{
	return x_pos;
}
float Ball::GetYPos()
{
	return y_pos;
}
float Ball::GetSpeed()
{
	return speed;
}
float Ball::GetXVectorSpeed()
{
	return x_vector_speed;
}
float Ball::GetYVectorSpeed()
{
	return y_vector_speed;
}
float Ball::GetRadius()
{
	return radius;
}


void Ball::SetXPos(float value)
{
	x_pos = value;
}
void Ball::SetYPos(float value)
{
	y_pos = value;
}
void Ball::SetSpeed(float value)
{
	speed = value;
}
void Ball::SetXVectorSpeed(float value)
{
	x_vector_speed = value;
}
void Ball::SetYVectorSpeed(float value)
{
	y_vector_speed = value;
}
void Ball::SetRadius(float value)
{
	radius = value;
}
