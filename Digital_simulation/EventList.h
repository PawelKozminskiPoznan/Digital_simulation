#pragma once
#include "Event.h"

class Event;
class EventList
{
public:
	void addEvent(Event *newEvent);
	void addToBegining(Event *newEvent);
	void removeEvent();
	int howMany();
	void sortEvent();
	void showList();
	int getFirstTime();
	void removeSelectedEvent(Event* selected);
	Event* getFirstEvent();
	Event* getLastEvent();
	bool lookForEvent(Event*);
	EventList();
	~EventList();
private:
	Event *root;
};

