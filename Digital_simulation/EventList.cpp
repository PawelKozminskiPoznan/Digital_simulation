#include "pch.h"
#include "EventList.h"
#include <iostream>
using namespace std;

void EventList::addEvent(Event *newEvent)
{
	Event *pom = root;
	bool isChild = true;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			pom->next = newEvent;
			isChild = false;
		}
		else
		{
			isChild = true;
			pom = pom->next;
		}
	}
}

void EventList::addToBegining(Event *newEvent)
{
	if (root->next)
	{
		Event *pom = root->next;
		root->next = newEvent;
		newEvent->next = pom;
	}
	else
		root->next = newEvent;
}

void EventList::removeEvent()
{
	if (root->next)
	{
		if (root->next->next)
		{
			Event *pom = root->next->next;
			root->next->next = nullptr;
			root->next = pom;
		}
		else
		{
			root->next = nullptr;
		}

	}

}

int EventList::howMany()
{
	Event *pom = root;
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

void EventList::sortEvent()
{
	Event *pom = root;
	bool sorted = false;
	int finishSort = 0;
	int how = howMany();
	while (!sorted)
	{
		pom = root;
		finishSort = 0;
		for (int i = 0; i < how - 1; i++)
		{
			if (pom->next->next)
			{
				if (pom->next->getTime() > pom->next->next->getTime())
				{
					Event *pom2, *pom3;
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
		{
			sorted = true;
		}
	}


}

void EventList::showList()
{
	Event *pom = root;
	bool isChild = true;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			pom->showTime();
			isChild = false;
		}
		else
		{
			isChild = true;
			pom->showTime();
			pom = pom->next;
		}
	}
}

int EventList::getFirstTime()
{
	return root->next->getTime();
}


void EventList::removeSelectedEvent(Event* selected)
{
	Event *pom = root;
	bool isChild = true;
	if (root->next)
	{
		while (isChild)
		{
			if (pom->next == selected && pom->next)
			{
				if (pom->next->next)
				{
					Event *pom2 = pom->next;
					pom->next = pom->next->next;
					pom2->next = nullptr;
				}
				else
				{
					pom->next = nullptr;
				}

				isChild = false;
			}
			else if (pom->next)
			{
				isChild = true;
				pom = pom->next;
			}
			else
			{
				isChild = false;
			}
		}
	}



}

bool EventList::lookForEvent(Event* a)
{
	Event *pom = root;
	bool isChild = true;
	if (root->next)
	{
		while (isChild)
		{
			if (pom->next == a && pom->next)
			{
				return true;
				isChild = false;
			}
			else if (pom->next)
			{
				isChild = true;
				pom = pom->next;
			}
			else
			{
				isChild = false;
			}
		}
	}
	return false;

}

Event* EventList::getFirstEvent()
{
	return root->next;
}

Event* EventList::getLastEvent()
{
	Event *pom = root;
	bool isChild = true;
	while (isChild)
	{
		if (pom->next == nullptr)
		{
			return pom;
			isChild = false;
		}
		else
		{
			isChild = true;
			pom = pom->next;
		}
	}
}

EventList::EventList()
{
	root = new Event();
	root->setTime(-1);
}


EventList::~EventList()
{
}
