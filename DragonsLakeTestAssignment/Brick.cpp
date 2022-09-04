#include "Brick.h"

Brick::Brick()
{

}
Brick::~Brick()
{

}
bool Brick::HitBrick()
{
	return true;
}
void Brick::DrawBrick() 
{

}
float Brick::GetWidth()
{
	return width;
}
float Brick::GetHeight()
{
	return height;
}
int Brick::GetX()
{
	return x_pos;
}
int Brick::GetY()
{
	return y_pos;
}
Brick::BrickType Brick::GetType()
{
	return type;
}