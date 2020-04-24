#pragma once
#include "Process.h"
#include "BloodDonationPoint.h"

class DonorComingProcess :
	public Process
{
public:
	void execute();
	DonorComingProcess(BloodDonationPoint bPoint,EventList *el);
	~DonorComingProcess();
};

