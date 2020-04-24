#pragma once
#include "Process.h"
#include "BloodDonationPoint.h"
#include "UtilizationProcess.h"
#include "QueueRecipient.h"
#include "RecipientProcess.h"
#include "ScientificResearchProcess.h"

class RecipientProcess;
class QueueRecipient;
class OrderSpecialProcess :
	public Process
{
public:
	void execute() override;
	void activate(int time);
	void setAmountOfSpecialOrder(int);
	OrderSpecialProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, UtilizationProcess *uP,
		RecipientProcess *rProcess, ScientificResearchProcess *scProc,bool gr);
	~OrderSpecialProcess();
private:
	Event*myEvent;
	UtilizationProcess *uProcess;
	QueueRecipient *qRecipient;
	RecipientProcess *recipientProcess;
	ScientificResearchProcess *scResearchProcess;
	int amountOfSpecialOrder;
	bool group;
};