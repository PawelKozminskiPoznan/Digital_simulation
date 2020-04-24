#include "pch.h"
#include "UnitBlood.h"

int UnitBlood::getTimeOfBlood()
{
	return timeToLive;
}

bool UnitBlood::showGroup()
{
	return group;
}


UnitBlood::UnitBlood(int tToLive)
{
	next = nullptr;
	timeToLive = tToLive;
	if (gen.uniform() > 0.6)
		group = true;
	else
		group = false;
}

UnitBlood::UnitBlood(int tToLive, bool gr)
{
	next = nullptr;
	timeToLive = tToLive;
	group = gr;
}


UnitBlood::~UnitBlood()
{
}
