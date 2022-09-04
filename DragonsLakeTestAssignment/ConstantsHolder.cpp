#include "ConstantsHolder.h"

ConstantsHolder::ConstantsHolder() { }

ConstantsHolder* ConstantsHolder::instance = nullptr;

ConstantsHolder* ConstantsHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ConstantsHolder();
	}
	return instance;
}