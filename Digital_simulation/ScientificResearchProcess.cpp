#include "pch.h"
#include "ScientificResearchProcess.h"
#include <iostream>

using namespace std;

void ScientificResearchProcess::execute()
{
	cout << "'ScientificResearcheProcess': Badania naukowe" << endl;
	if (timeOfStart + 300 == bloodPoint->getClock())
	{
		for (int i = 0; i < amountOfBloodUniform; i++)
		{
			queueBlood->removeBlood();
			amountOfBloodStatistic++;
		}
		cout << "- wyslano " << amountOfBloodUniform << " jednostek krwi" << endl;
	}
	else
	{
		cout << "- nie wyslano jednostek krwi" << endl;
	}
	timeOfStart = 0;
}

void ScientificResearchProcess::activate(int time)
{
	cout << "'ScientificResearcheProcess': Badania naukowe" << endl;
	timeOfStart = bloodPoint->getClock();
	myEvent->setTime(bloodPoint->getClock() + time);
	eList->addEvent(myEvent);
	cout << "- zaplanowanie wyslania jednostek krwi" << endl;
	eList->sortEvent();
}

void ScientificResearchProcess::checkCondition(bool group)
{
	if(group)
	{
		if (bloodPoint->getAmountBloodB() < 30)
		{
			eList->removeSelectedEvent(myEvent);
			timeOfStart = 0;
			cout << "'ScientificResearcheProcess': Badania naukowe gr.B" << endl;
			cout << "- anulowanie wyslania jednostek krwi na skutek nie spelnienie warunku" << endl;
		}

		else if (timeOfStart == 0)
		{
			activate(300);
		}
	}
	else
	{
		if (bloodPoint->getAmountBloodA() < 30)
		{
			eList->removeSelectedEvent(myEvent);
			timeOfStart = 0;
			cout << "'ScientificResearcheProcess': Badania naukowe gr.A" << endl;
			cout << "- anulowanie wyslania jednostek krwi na skutek nie spelnienie warunku" << endl;
		}

		else if (timeOfStart == 0)
		{
			activate(300);
		}
	}
	

}
void ScientificResearchProcess::setAmountOfBloodUniform_5_10(int number)
{
	amountOfBloodUniform = number;
}

int ScientificResearchProcess::getAmountOfBloodStatistic()
{
	return amountOfBloodStatistic;
}

void ScientificResearchProcess::clearAmountOfBloodStatistic()
{
	amountOfBloodStatistic = 0;
}

ScientificResearchProcess::ScientificResearchProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood)
	: Process(bPoint, el, qBlood)

{
	amountOfBloodUniform = 7;
	timeOfStart = 0;
	myEvent = new Event(this);
	amountOfBloodStatistic = 0;
}


ScientificResearchProcess::~ScientificResearchProcess()
{
}