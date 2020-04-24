#pragma once
#include "Process.h"

class UtilizationProcess :
	public Process
{
public:
	void execute() override;
	void setHowManyToRemove(int);
	int getHowManyToRemove();
	int getAmountOfUtilizeBloodStatistics();
	void clearAmountOfUtilizeBloodStatistics();
	void activate(int time);
	UtilizationProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood);
	~UtilizationProcess();
private:
	int howManyToRemove;
	int amountOfUtilizeBloodStatistics;
	Event *myEvent;
};

