#pragma once
#include "UnitBlood.h"
#include "BloodDonationPoint.h"

class Statistics;
class QueueUnitBlood
{
public:
	void addBlood(UnitBlood *newBlood);
	void removeBlood();
	int howMany();
	void sortBlood();
	void showBlood();
	int showTimeBlood();
	int getAmoutnOfBloodStatistics();
	void clearAmountOfBloodStatistics();
	void setBloodDonationPoint(BloodDonationPoint*);
	QueueUnitBlood();
	~QueueUnitBlood();
private:
	BloodDonationPoint *bPoint;
	UnitBlood *root;
	int amoutnOfBloodStatistics;
	Statistics *stat;
};

