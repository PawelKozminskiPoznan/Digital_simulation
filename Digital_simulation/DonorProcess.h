#pragma once
#include "Process.h"
#include "UtilizationProcess.h"
#include "RecipientProcess.h"


class RecipientProcess;
class DonorProcess :
	public Process
{
public:
	void execute() override;
	void setTimeOfComingDonorExponential_850(int);
	DonorProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, UtilizationProcess *uP,
		RecipientProcess *rProcess);
	~DonorProcess();
private:
	Event *myEvent;
	UtilizationProcess *uProcess;
	RecipientProcess *recipientProcess;
	int timeOfComingDonorExponential_850;
};

