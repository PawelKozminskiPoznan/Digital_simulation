#include "pch.h"
#include "UtilizationProcess.h"
#include <iostream>

using namespace std;


void UtilizationProcess::execute()
{
	bool utilization = false;
	int howMany = 0;
	for (int i = 0; i < howManyToRemove; i++)
	{
		if (queueBlood->showTimeBlood() == bloodPoint->getClock())
		{
			queueBlood->removeBlood();
			amountOfUtilizeBloodStatistics++;
			utilization = true;
			howMany++;
		}
	}
	cout << "'UtilizationProcess': Utylizacja jednostek krwi" << endl;
	if (utilization)
	{
		cout << "- utylizacja " << howMany << " jednostek krwi z " << howManyToRemove << " planowanych" << endl;
	}
	else
	{
		cout << "- utylizacja nie odbyla sie ,poniewaz dane jednostki krwi" << endl;
		cout << "  zostaly wykorzystane wczesniej" << endl;
	}
}

void UtilizationProcess::activate(int time)
{
	if (eList->lookForEvent(myEvent))
	{
		Event *secondEvent = new Event(this);
		secondEvent->setTime(bloodPoint->getClock() + time);
		eList->addEvent(secondEvent);
		eList->sortEvent();
	}
	else
	{
		myEvent->setTime(bloodPoint->getClock() + time);
		eList->addEvent(myEvent);
		eList->sortEvent();
	}
}

void UtilizationProcess::setHowManyToRemove(int amount)
{
	howManyToRemove = amount;
}

int UtilizationProcess::getHowManyToRemove()
{
	return howManyToRemove;
}

int UtilizationProcess::getAmountOfUtilizeBloodStatistics()
{
	return amountOfUtilizeBloodStatistics;
}

void UtilizationProcess::clearAmountOfUtilizeBloodStatistics()
{
	amountOfUtilizeBloodStatistics = 0;
}

UtilizationProcess::UtilizationProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood)
	: Process(bPoint, el, qBlood)
{
	howManyToRemove = 0;
	amountOfUtilizeBloodStatistics = 0;
	myEvent = new Event(this);
}


UtilizationProcess::~UtilizationProcess()
{
}
