#pragma once
#include "Generators.h"

class UnitBlood
{
public:
	UnitBlood *next;
	int getTimeOfBlood();
	bool showGroup();
	UnitBlood(int tToLive);
	UnitBlood(int tToLive,bool gr);
	~UnitBlood();
private:
	int timeToLive;
	bool group;
	Generators gen;
};

