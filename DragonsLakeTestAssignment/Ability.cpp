#include "Ability.h"


float Ability::GetAdditionalSpeed()
{
	return additional_speed;
}
Ability::Ability()
{
}
bool Ability::IsEnd(int cur_time)
{
	return cur_time - start_time > active_time; // true, if must be end
}