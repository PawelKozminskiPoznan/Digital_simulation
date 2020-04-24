#include "pch.h"
#include "Event.h"
#include <iostream>

using namespace std;

void Event::setTime(int time)
{
	eventTime = time;
}

void Event::showTime()
{
	cout << "Czas zdarzenia : " << eventTime << endl;
}

int Event::getTime()
{
	return eventTime;
}

Process* Event::getProcess()
{
	return myProcess;
}

Event::Event(Process *proc)
{
	myProcess = proc;
	next = nullptr;
	phase = 3;
	eventTime = 0;
	planRecipient = false;
}

Event::Event()
{
	myProcess = nullptr;
	next = nullptr;
	phase = 3;
	eventTime = 0;
	planRecipient = false;
}

Event::~Event()
{
}
