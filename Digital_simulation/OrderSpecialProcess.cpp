#include "pch.h"
#include "OrderSpecialProcess.h"
#include <iostream>

using namespace std;

void OrderSpecialProcess::execute()
{
	if (group)
	{
		cout << "'OrderSpecialProcess': Specialne zamowienie gr.B" << endl;
		bloodPoint->clearSpecialOrderFlagB();
	}
	else
	{
		cout << "'OrderSpecialProcess': Specialne zamowienie gr.A" << endl;
		bloodPoint->clearSpecialOrderFlagA();
	}
	for (int i = 0; i < amountOfSpecialOrder; i++)
	{
		UnitBlood *blood = new UnitBlood(bloodPoint->getClock() + bloodPoint->getTimeOfUseBloodFromOrder(),group);
		queueBlood->addBlood(blood);
	}
	cout << "- dodanie " << amountOfSpecialOrder << " jednostek krwi do koleji krwi" << endl;
	cout << "- zaplanowanie utylizacji jednostek krwi" << endl;
	recipientProcess->reactive(group);
	scResearchProcess->checkCondition(group);
	uProcess->setHowManyToRemove(amountOfSpecialOrder);
	uProcess->activate(bloodPoint->getTimeOfUseBloodFromOrder());
}

void OrderSpecialProcess::activate(int time)
{
	myEvent->setTime(bloodPoint->getClock() + time);
	eList->addEvent(myEvent);
	eList->sortEvent();
	if (group)
	{
		bloodPoint->setSpecialOrderFlagB();
	}
	else
	{
		bloodPoint->setSpecialOrderFlagA();
	}
}

void OrderSpecialProcess::setAmountOfSpecialOrder(int number)
{
	amountOfSpecialOrder = number;
}

OrderSpecialProcess::OrderSpecialProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, UtilizationProcess *uP,
	RecipientProcess *rProcess, ScientificResearchProcess *scProc, bool gr)
	: Process(bPoint, el, qBlood), uProcess(uP), recipientProcess(rProcess), scResearchProcess(scProc),group(gr)
{
	myEvent = new Event(this);
	amountOfSpecialOrder = 20;
}


OrderSpecialProcess::~OrderSpecialProcess()
{
}

