#include "pch.h"
#include "Recipient.h"

int Recipient::getNeededBlood()
{
	return unitBloodNeeded;
}

bool Recipient::showGruop()
{
	return group;
}


Recipient::Recipient(int amount)
{
	unitBloodNeeded = amount;
	next = nullptr;
	number_wsk = 0;
	if (gen.uniform() < 0.4)
		group = false;
	else
		group = true;
}

Recipient::~Recipient()
{
}
