#pragma once
#include "Process.h"
#include "Recipient.h"
#include "QueueRecipient.h"
#include "OrderSpecialProcess.h"
#include "OrderProcess.h"
#include "ScientificResearchProcess.h"


class OrderSpecialProcess;
class OrderProcess;
class QueueRecipient;
class RecipientProcess :
	public Process
{
public:
	void setOrderA(OrderProcess*);
	void setSpecialOrderA(OrderSpecialProcess*);
	void setOrderB(OrderProcess*);
	void setSpecialOrderB(OrderSpecialProcess*);
	void execute() override;
	void activate(int time);
	void reactive(bool);
	int getBloodPacientStatistics();
	void clearSpecialOrderID();
	void clearBloodPacientStatistics();
	int getSpecialOrderID();
	void setTimeOfOrderExponential_1900(int);
	void setTimeOfRecipientExponential_200(int);
	void setTimeOfSpecialOrderNormal_400(int);
	void setNeededBloodGeometric_0_23(int);
	RecipientProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBloodA, QueueUnitBlood *qBloodB,
		QueueRecipient *qReciA, QueueRecipient *qReciB,ScientificResearchProcess *scProcA, ScientificResearchProcess *scProcB);
	~RecipientProcess();
private:
	EventList *events;
	Event** wsk_tab;
	Event** wsk_tab2;
	QueueUnitBlood *queueBloodB;
	Recipient *nRecipient;
	QueueRecipient *qRecipientA;
	QueueRecipient *qRecipientB;
	ScientificResearchProcess *scResearchProcessA;
	ScientificResearchProcess *scResearchProcessB;
	OrderSpecialProcess *specialOrderA;
	OrderSpecialProcess *specialOrderB;
	OrderProcess *orderA;
	OrderProcess *orderB;
	int numberEvent;
	int recipFromQueueA;
	int recipFromQueueB;
	int bloodPacientStatistics;
	int specialOrderID;
	int timeOfOrderExponential_1900;
	int timeOfRecipientExponential_200;
	int timeOfSpecialOrderNormal_400;
	int neededBloodGeometric_0_23;
};