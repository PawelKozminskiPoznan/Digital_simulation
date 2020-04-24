#include "pch.h"
#include "RecipientProcess.h"
#include <iostream>

using namespace std;


void RecipientProcess::execute()
{
	bool active = true;
	bool actualGroup;
	if (recipFromQueueA > 0)
	{
		recipFromQueueA--;
		numberEvent = qRecipientA->getRecipient(1)->number_wsk;
		actualGroup = false;
	}
	else if(recipFromQueueB > 0)
	{
		recipFromQueueB--;
		numberEvent = qRecipientB->getRecipient(1)->number_wsk;
		actualGroup = true;
	}
	else if (events->getFirstEvent() && events->getFirstEvent()->getTime() == bloodPoint->getClock())
	{
		numberEvent = events->getFirstEvent()->number;
		events->removeEvent();
	}
	phase = wsk_tab[numberEvent]->phase;
	while (active)
	{
		switch (phase)
		{
		case 0:
		{
			cout << "'Recipient Process': Obsluga biorcy 1.etap" << endl;
			nRecipient = new Recipient(neededBloodGeometric_0_23);
			if(nRecipient->showGruop())
				qRecipientB->addRecipient(nRecipient);
			else
				qRecipientA->addRecipient(nRecipient);
			actualGroup = nRecipient->showGruop();
			wsk_tab[numberEvent]->phase = 1;
			cout << "- dodanie pacjenata do koleji pacjentow" << endl;
			if (queueBlood->howMany() < nRecipient->getNeededBlood() && !nRecipient->showGruop())
			{
				active = false;
				if (!bloodPoint->checkSpecialOrderFlagA())
				{
					specialOrderA->activate(timeOfSpecialOrderNormal_400);
					specialOrderID++;
					cout << "- zaplanowanie przyjscia specjalnego zamowienia" << endl;
				}
				int num = numberEvent;
				activate(timeOfRecipientExponential_200);
				numberEvent = num;
				wsk_tab[numberEvent]->planRecipient = true;
				nRecipient->number_wsk = numberEvent;
				cout << "- zaplanowanie kolejnego procesu 'Recipient process' " << endl;
			}
			else if (queueBloodB->howMany() < nRecipient->getNeededBlood() && nRecipient->showGruop())
			{
				active = false;
				if (!bloodPoint->checkSpecialOrderFlagB())
				{
					specialOrderB->activate(timeOfSpecialOrderNormal_400);
					specialOrderID++;
					cout << "- zaplanowanie przyjscia specjalnego zamowienia" << endl;
				}
				int num = numberEvent;
				activate(timeOfRecipientExponential_200);
				numberEvent = num;
				wsk_tab[numberEvent]->planRecipient = true;
				nRecipient->number_wsk = numberEvent;
				cout << "- zaplanowanie kolejnego procesu 'Recipient process' " << endl;
			}
			phase = 1;
			break;
		}
		case 1:
		{
			cout << "'Recipient process': Obsluga biorcy 2.etap" << endl;
			if (wsk_tab[numberEvent]->planRecipient == true)
			{
				if (!actualGroup)
					nRecipient = qRecipientA->getFirstRecipient();
				else
					nRecipient = qRecipientB->getFirstRecipient();
			}
			if(!nRecipient->showGruop())
			{
				for (int i = 0; i < nRecipient->getNeededBlood(); i++)
				{
					queueBlood->removeBlood();
					bloodPacientStatistics++;
				}
				qRecipientA->removeSelectedRecipient(nRecipient);
			}
			else
			{
				for (int i = 0; i < nRecipient->getNeededBlood(); i++)
				{
					queueBloodB->removeBlood();
					bloodPacientStatistics++;
				}
				qRecipientB->removeSelectedRecipient(nRecipient);
			}
			cout << "- usuniecie pacjenta z koleji pacjentow" << endl;
			cout << "- usuniecie krwi z kolejki krwi" << endl;
			if (wsk_tab[numberEvent]->planRecipient == false)
			{
				int num = numberEvent;
				activate(timeOfRecipientExponential_200);
				numberEvent = num;
				wsk_tab[numberEvent]->planRecipient = true;
				cout << "- zaplanowanie kolejnego procesu 'Recipient process'" << endl;
			}
			active = false;
			wsk_tab[numberEvent]->planRecipient = false;
			wsk_tab[numberEvent]->phase = 3;
			if (actualGroup)
				scResearchProcessB->checkCondition(actualGroup);
			else
				scResearchProcessA->checkCondition(actualGroup);
			break;
		}
		}
	}
	if (bloodPoint->getAmountBloodA() < bloodPoint->getMinAMountBlood() && !bloodPoint->checkOrderFlagA())
	{
		orderA->activate(timeOfOrderExponential_1900,false);
		bloodPoint->setOrderFlagA();
		cout << "- zlozenie standardowego zamowienia gr.A" << endl;
	}
	if (bloodPoint->getAmountBloodB() < bloodPoint->getMinAMountBlood() && !bloodPoint->checkOrderFlagB())
	{
		orderB->activate(timeOfOrderExponential_1900,true);
		bloodPoint->setOrderFlagB();
		cout << "- zlozenie standardowego zamowienia gr.B" << endl;
	}
}

void RecipientProcess::activate(int time)
{
	bool condition = true;
	int i = 0;
	while (condition)
	{
		if (wsk_tab[i]->phase == 3)
		{
			numberEvent = i;
			condition = false;
		}
		else
		{
			i++;
		}
	}
	wsk_tab[numberEvent]->setTime(bloodPoint->getClock() + time);
	wsk_tab2[numberEvent]->setTime(bloodPoint->getClock() + time);
	wsk_tab[numberEvent]->phase = 0;
	wsk_tab[numberEvent]->planRecipient = false;
	events->addEvent(wsk_tab2[numberEvent]);
	wsk_tab[numberEvent]->number = numberEvent;
	wsk_tab2[numberEvent]->number = numberEvent;
	eList->addEvent(wsk_tab[numberEvent]);
	eList->sortEvent();
}

void RecipientProcess::reactive(bool group)
{
	bool make = true;
	int recip = 1;
	int sumNeeded = 0;
	if(!group)
	{
		while (make)
		{
			make = false;
			if (qRecipientA->howManyRecipients() > 0)
			{
				sumNeeded += qRecipientA->getRecipient(recip)->getNeededBlood();
				if (qRecipientA->howManyRecipients() >= recip && queueBlood->howMany() >= sumNeeded)
				{
					if (recip == qRecipientA->howManyRecipients())
						make = false;
					else
						make = true;
					int nr = qRecipientA->getRecipient(recip)->number_wsk;
					cout << "- reaktywacja procecu 'RecipientProcess'" << endl;
					wsk_tab[nr]->setTime(bloodPoint->getClock());
					eList->addToBegining(wsk_tab[nr]);
					eList->sortEvent();
					recipFromQueueA = recip;
					recip++;
				}
			}

		}
	}
	else
	{
		while (make)
		{
			make = false;
			if (qRecipientB->howManyRecipients() > 0)
			{
				sumNeeded += qRecipientB->getRecipient(recip)->getNeededBlood();
				if (qRecipientB->howManyRecipients() >= recip && queueBlood->howMany() >= sumNeeded)
				{
					if (recip == qRecipientB->howManyRecipients())
						make = false;
					else
						make = true;
					int nr = qRecipientB->getRecipient(recip)->number_wsk;
					cout << "- reaktywacja procecu 'RecipientProcess'" << endl;
					wsk_tab[nr]->setTime(bloodPoint->getClock());
					eList->addToBegining(wsk_tab[nr]);
					eList->sortEvent();
					recipFromQueueB = recip;
					recip++;
				}
			}

		}
	}
	
}

void RecipientProcess::setOrderA(OrderProcess *ord)
{
	orderA = ord;
}

void RecipientProcess::setSpecialOrderA(OrderSpecialProcess *spec)
{
	specialOrderA = spec;
}

void RecipientProcess::setOrderB(OrderProcess *ord)
{
	orderB = ord;
}

void RecipientProcess::setSpecialOrderB(OrderSpecialProcess *spec)
{
	specialOrderB = spec;
}

int RecipientProcess::getBloodPacientStatistics()
{
	return bloodPacientStatistics;
}

int RecipientProcess::getSpecialOrderID()
{
	return specialOrderID;
}

void RecipientProcess::clearSpecialOrderID()
{
	specialOrderID = 0;
}

void RecipientProcess::clearBloodPacientStatistics()
{
	bloodPacientStatistics = 0;
}

void RecipientProcess::setTimeOfOrderExponential_1900(int number)
{
	timeOfOrderExponential_1900 = number;
}
void RecipientProcess::setTimeOfRecipientExponential_200(int number)
{
	timeOfRecipientExponential_200 = number;
}
void RecipientProcess::setTimeOfSpecialOrderNormal_400(int number)
{
	timeOfSpecialOrderNormal_400 = number;
}
void RecipientProcess::setNeededBloodGeometric_0_23(int number)
{
	neededBloodGeometric_0_23 = number;
}

RecipientProcess::RecipientProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBloodA, QueueUnitBlood *qBloodB,
	QueueRecipient *qReciA, QueueRecipient *qReciB, ScientificResearchProcess *scProcA, ScientificResearchProcess *scProcB)
	:Process(bPoint, el, qBloodA), queueBloodB(qBloodB), qRecipientA(qReciA), qRecipientB(qReciB), scResearchProcessA(scProcA),
	scResearchProcessB(scProcB)
{
	numberEvent = 0;
	recipFromQueueA = 0;
	recipFromQueueB = 0;
	bloodPacientStatistics = 0;
	specialOrderID = 0;
	wsk_tab = new Event*[100];
	for (int i = 0; i < 100; i++)
	{
		wsk_tab[i] = new Event(this);
	}
	wsk_tab2 = new Event*[100];
	for (int i = 0; i < 100; i++)
	{
		wsk_tab2[i] = new Event(this);
	}
	events = new EventList();
}


RecipientProcess::~RecipientProcess()
{
}
