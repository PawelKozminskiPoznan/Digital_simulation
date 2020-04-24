#pragma once
#include "Process.h"
#include "BloodDonationPoint.h"

class ScientificResearchProcess :
	public Process
{
public:
	void execute() override;
	void activate(int time);
	void checkCondition(bool);
	void setAmount(int);
	void setAmountOfBloodUniform_5_10(int);
	int getAmountOfBloodStatistic();
	void clearAmountOfBloodStatistic();
	ScientificResearchProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood);
	~ScientificResearchProcess();
private:
	Event *myEvent;
	int timeOfStart;
	int amountOfBloodUniform;
	int amountOfBloodStatistic;
};
