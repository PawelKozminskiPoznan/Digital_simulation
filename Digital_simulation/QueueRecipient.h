#pragma once
#include "Recipient.h"
#include "Statistics.h"

class Statistics;
class QueueRecipient
{
public:
	void addRecipient(Recipient *add);
	void removeRecipient();
	void showRecipient();
	int howManyRecipients();
	int getAmountOfPatientStatistics();
	void clearAmountOfPatientStatistics();
	void removeSelectedRecipient(Recipient* selected);
	void setBloodDonationPoint(BloodDonationPoint*);
	Recipient* getFirstRecipient();
	Recipient* getRecipient(int number);
	QueueRecipient();
	~QueueRecipient();
private:
	Recipient *root;
	Statistics *stat;
	BloodDonationPoint *bloodPoint;
	int amountOfPatientStatistics;
};

