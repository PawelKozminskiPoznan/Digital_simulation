#pragma once
#include "Process.h"
#include "BloodDonationPoint.h"
#include "UtilizationProcess.h"
#include "RecipientProcess.h"
#include "ScientificResearchProcess.h"

class RecipientProcess;
class OrderProcess :
	public Process
{
public:
	void execute() override;
	void activate(int time,bool);
	void setAmountOfOrder(int);
	int getAmountOfOrder();
	int getOrderID();
	void clearOrderID();
	OrderProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, UtilizationProcess *uP,
		RecipientProcess *rProcess, ScientificResearchProcess *scProc,	bool gr);
	~OrderProcess();
private:
	Event *myEvent;
	int amountOfOrder;
	RecipientProcess *recipientProcess;
	UtilizationProcess *uProcess;
	ScientificResearchProcess *scResearchProcess;
	bool group;
	int orderID;
};

