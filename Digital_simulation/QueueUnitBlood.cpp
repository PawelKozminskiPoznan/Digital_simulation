#include "pch.h"
#include "QueueUnitBlood.h"
#include <iostream>
#include <fstream>

using namespace std;

void QueueUnitBlood::addBlood(UnitBlood *newBlood)
{
	UnitBlood *pom = root;
	bool isChild = false;
	do
	{
		if (pom->next == nullptr)
		{
			pom->next = newBlood;
			isChild = false;
		}
		else
		{
			isChild = true;
			pom = pom->next;
		}
	} while (isChild);
	if(newBlood->showGroup())
		bPoint->setAmountBloodB(bPoint->getAmountBloodB() + 1);
	else
		bPoint->setAmountBloodA(bPoint->getAmountBloodA() + 1);
	sortBlood();
	amoutnOfBloodStatistics++;

	ofstream result;
	result.open("kolejka_krwi_time.xls", ios::out | ios::app);
	result << bPoint->getClock() << endl;
	result.close();
	result.open("kolejka_krwi.xls", ios::out | ios::app);
	result << howMany() << endl;
	result.close();
}

void QueueUnitBlood::removeBlood()
{
	if (root->next)
	{
		UnitBlood *pom = root->next;
		root->next = root->next->next;
		if(pom->showGroup())
			bPoint->setAmountBloodB(bPoint->getAmountBloodB() - 1);
		else
			bPoint->setAmountBloodA(bPoint->getAmountBloodA() - 1);
		delete pom;
	}

}

int QueueUnitBlood::howMany()
{
	UnitBlood *pom = root;
	bool isChild = true;
	int howManyChild = 0;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			return howManyChild;
			isChild = false;
		}
		else
		{
			isChild = true;
			howManyChild++;
			pom = pom->next;
		}
	}
}

void QueueUnitBlood::sortBlood()
{
	UnitBlood *pom = root;
	bool sorted = false;
	int finishSort = 0;
	while (!sorted)
	{
		pom = root;
		finishSort = 0;
		for (int i = 0; i < howMany() - 1; i++)
		{
			if (pom->next->next)
			{
				if (pom->next->getTimeOfBlood() > pom->next->next->getTimeOfBlood())
				{
					UnitBlood *pom2, *pom3;
					pom2 = pom->next;
					pom3 = pom->next->next;
					if (pom3->next)
						pom2->next = pom3->next;
					else
						pom2->next = nullptr;
					pom->next = pom3;
					pom3->next = pom2;
					pom = pom->next;
					sorted = false;
					finishSort = 0;

				}
				else
				{
					pom = pom->next;
					finishSort++;
				}
			}
		}
		if (finishSort == howMany() - 1)
			sorted = true;
	}


}

void QueueUnitBlood::showBlood()
{
	UnitBlood *pom = root;
	bool isChild = true;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			cout << "Krew - termin: " << pom->getTimeOfBlood() << endl;
			isChild = false;
		}
		else
		{
			isChild = true;
			cout << "Krew - termin: " << pom->getTimeOfBlood() << endl;
			pom = pom->next;
		}
	}
	cout << endl;
}

int QueueUnitBlood::showTimeBlood()
{
	if (root->next)
		return root->next->getTimeOfBlood();
	else
		return 0;
}

int QueueUnitBlood::getAmoutnOfBloodStatistics()
{
	return amoutnOfBloodStatistics;
}

void QueueUnitBlood::clearAmountOfBloodStatistics()
{
	amoutnOfBloodStatistics = 0;
}

void QueueUnitBlood::setBloodDonationPoint(BloodDonationPoint *bP)
{
	bPoint = bP;
}

QueueUnitBlood::QueueUnitBlood()
{
	root = new UnitBlood(-1);
	amoutnOfBloodStatistics = 0;
}


QueueUnitBlood::~QueueUnitBlood()
{
}
