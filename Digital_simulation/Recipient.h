#pragma once
#include "Generators.h"

class Recipient
{
public:
	Recipient *next;
	int number_wsk;
	int getNeededBlood();
	bool showGruop();
	Recipient(int amount);
	~Recipient();
private:
	Generators gen;
	int unitBloodNeeded;
	bool group;
};

