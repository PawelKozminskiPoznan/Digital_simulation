#pragma once
#include "EventList.h"
#include "BloodDonationPoint.h"
#include "QueueUnitBlood.h"

class EventList;
class Event;
class Process
{
public:
	EventList *eList;
	BloodDonationPoint *bloodPoint;
	QueueUnitBlood *queueBlood;
	void virtual execute() = 0;
	void activate(int time);
	int phase;
	Process(BloodDonationPoint *bPoint,EventList *el,QueueUnitBlood *qBlood);
	virtual ~Process();
private:
	Event *myEvent;
};

