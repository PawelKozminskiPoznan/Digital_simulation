#include "pch.h"
#include "QueueRecipient.h"
#include <iostream>

using namespace std;

void QueueRecipient::addRecipient(Recipient *add)
{
	Recipient *pom = root;
	bool isChild = false;
	do
	{
		if (pom->next == nullptr)
		{
			pom->next = add;

			isChild = false;
		}
		else
		{
			isChild = true;
			pom = pom->next;
		}
	} while (isChild);
	//stat.saveStatsToFile2(howManyRecipients(),bloodPoint->getClock(), "kolejka");
	amountOfPatientStatistics++;
}

void QueueRecipient::removeRecipient()
{
	Recipient *pom;
	if (root->next->next == nullptr)
	{
		pom = root->next;
		root->next = nullptr;
		delete pom;
	}
	else
	{
		Recipient *pom2 = root->next->next;
		pom = root->next;
		root->next = pom2;
		delete pom;
	}
}

void QueueRecipient::showRecipient()
{
	Recipient *pom = root;
	bool isChild = false;
	cout << "Kolejka pacjentow : " << endl;
	do
	{
		if (pom->next == nullptr)
		{
			cout << "nr = " << pom->number_wsk << " potrzebna krew: " << pom->getNeededBlood() << endl;
			isChild = false;
		}
		else
		{
			isChild = true;
			cout << "nr = " << pom->number_wsk << " potrzebna krew: " << pom->getNeededBlood() << endl;
			pom = pom->next;
		}
	} while (isChild);
}

int QueueRecipient::howManyRecipients()
{
	Recipient *pom = root;
	bool isChild = false;
	int howMany = 0;
	do
	{
		if (pom->next == nullptr)
		{

			return howMany;
			isChild = false;
		}
		else
		{
			isChild = true;
			howMany++;
			pom = pom->next;
		}
	} while (isChild);
}

int QueueRecipient::getAmountOfPatientStatistics()
{
	return amountOfPatientStatistics;
}

Recipient* QueueRecipient::getFirstRecipient()
{
	return root->next;
}

Recipient* QueueRecipient::getRecipient(int number)
{
	Recipient *pom = root;
	bool isChild = false;
	int pom_number = 0;
	do
	{
		pom_number++;
		if (pom->next == nullptr)
		{
			isChild = false;
		}
		else
		{
			isChild = true;
			pom = pom->next;
		}
		if (pom_number == number)
			return pom;
	} while (isChild);
}


void QueueRecipient::removeSelectedRecipient(Recipient* selected)
{
	Recipient *pom = root;
	bool isChild = true;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			isChild = false;
		}
		else
		{
			isChild = true;
			if (pom->next == selected)
			{
				if (pom->next->next)
				{
					Recipient *pom2 = pom->next;
					pom->next = pom->next->next;
					pom2->next = nullptr;
				}
				else
					pom->next = nullptr;
				isChild = false;
			}
			pom = pom->next;
		}
	}
}

void QueueRecipient::setBloodDonationPoint(BloodDonationPoint* bP)
{
	bloodPoint = bP;
}

void QueueRecipient::clearAmountOfPatientStatistics()
{
	amountOfPatientStatistics = 0;
}

QueueRecipient::QueueRecipient()
{
	root = new Recipient(-1);
	root->number_wsk = -1;
	amountOfPatientStatistics = 0;
	stat = new Statistics();
}

QueueRecipient::~QueueRecipient()
{
}
