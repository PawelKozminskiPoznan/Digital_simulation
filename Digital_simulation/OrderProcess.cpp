#include "pch.h"
#include "OrderProcess.h"
#include <iostream>

using namespace std;

void OrderProcess::execute()
{
	orderID++;
	if(group)
	{
		cout << "'OrderProcess': Standardowe zamowienie gr.B" << endl;
		bloodPoint->clearOrderFlagB();
	}
	else
	{
		cout << "'OrderProcess': Standardowe zamowienie gr.A" << endl;
		bloodPoint->clearOrderFlagA();
	}
	for (int i = 0; i < amountOfOrder; i++)
	{
		UnitBlood *blood = new UnitBlood(bloodPoint->getClock() + bloodPoint->getTimeOfUseBloodFromOrder(),group);
		queueBlood->addBlood(blood);
	}
	cout << "- dodanie " << amountOfOrder << " jednostek krwi do koleji krwi" << endl;
	cout << "- zaplanowanie utylizacji jednostek krwi" << endl;
	recipientProcess->reactive(group);
	scResearchProcess->checkCondition(group);
	uProcess->setHowManyToRemove(amountOfOrder);
	uProcess->activate(bloodPoint->getTimeOfUseBloodFromOrder());
}

void OrderProcess::activate(int time,bool group)
{
		myEvent->setTime(bloodPoint->getClock() + time);
		eList->addEvent(myEvent);
		eList->sortEvent();
		if (group)
		{
			bloodPoint->setOrderFlagB();
		}
		else
		{
			bloodPoint->setOrderFlagA();
		}
}

void OrderProcess::setAmountOfOrder(int number)
{
	amountOfOrder = number;
}

int OrderProcess::getAmountOfOrder()
{
	return amountOfOrder;
}

int OrderProcess::getOrderID()
{
	return orderID;
}

void OrderProcess::clearOrderID()
{
	orderID = 0;
}

OrderProcess::OrderProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, 
	UtilizationProcess *uP, RecipientProcess *rProcess, ScientificResearchProcess *scProc,bool gr)
	: Process(bPoint, el, qBlood),uProcess(uP), recipientProcess(rProcess), scResearchProcess(scProc),group(gr)
{
	myEvent = new Event(this);
	amountOfOrder = 40;
}

OrderProcess::~OrderProcess()
{
}

