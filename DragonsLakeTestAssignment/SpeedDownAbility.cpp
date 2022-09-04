#include "SpeedDownAbility.h"

SpeedDownAbility::SpeedDownAbility(int start_time)
{
	this->start_time = start_time;
	additional_speed = -40;
	active_time = 20000;
}