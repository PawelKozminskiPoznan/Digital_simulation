#include "pch.h"
#include "Process.h"
#include <iostream>

using namespace std;

void Process::activate(int time)
{
	myEvent->setTime(bloodPoint->getClock() + time); 
	eList->addEvent(myEvent); 
	eList->sortEvent(); 
}

Process::Process(BloodDonationPoint *bPoint, EventList *el,QueueUnitBlood *qBlood) : bloodPoint(bPoint),eList(el),queueBlood(qBlood)
{
	myEvent = new Event(this);
	phase = 0;
}

Process::~Process()
{
}

