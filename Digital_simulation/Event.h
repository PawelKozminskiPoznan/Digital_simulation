#pragma once
class Process;
class Event
{
public:
	bool planRecipient;
	int number;
	Event *next;
	int phase;
	void setTime(int time);
	void showTime();
	int getTime();
	Process* getProcess();
	Event(Process *proc);
	Event();
	~Event();
private:
	Process *myProcess;
	int eventTime;
};

