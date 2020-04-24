#pragma once
#include "Process.h"
#include "BloodDonationPoint.h"

class RecipientComingProcess :
	public Process
{
public:
	RecipientComingProcess(BloodDonationPoint bPoint,EventList *el);
	~RecipientComingProcess();
};

