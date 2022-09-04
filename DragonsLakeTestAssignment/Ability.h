#pragma once

class Ability
{
protected:
	float additional_speed; //In percentages
	int active_time; //In milliseconds
	int start_time;
public:
	float GetAdditionalSpeed();
	bool IsEnd(int);
	Ability();
};