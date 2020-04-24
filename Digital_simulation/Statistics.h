#pragma once
#include "BloodDonationPoint.h"
#include "DonorProcess.h"
#include "OrderSpecialProcess.h"
#include <string>

class RecipientProces;
class ScientificResearchProcess;
class OrderProcess;
class DonorProcess;

class Statistics
{
public:
	void viewStat();
	void printToFile();
	void saveStatsToFile(double data, std::string name);
	void saveStatsToFile2(double data, int time, std::string name);
	Statistics(BloodDonationPoint *bPoint, DonorProcess *dProc, OrderProcess *orderPA, OrderProcess *orderPB, QueueRecipient *recQA, QueueRecipient *recQB,
		QueueUnitBlood *bQA, QueueUnitBlood *bQB, ScientificResearchProcess *scPA,
		ScientificResearchProcess *scPB, UtilizationProcess *utilizationDonorA, UtilizationProcess *utilizationOrderA,
		UtilizationProcess *utilizationSpecialOrderA, UtilizationProcess *utilizationDonorB, UtilizationProcess *utilizationOrderB,
		UtilizationProcess *utilizationSpecialOrderB, RecipientProcess *recPr);
	Statistics();
	~Statistics();
private:
	BloodDonationPoint *bloodPoint;
	DonorProcess *dProcess;
	OrderProcess *orderProcA;
	OrderProcess *orderProcB;
	QueueRecipient *recipientQA;
	QueueRecipient *recipientQB;
	QueueUnitBlood *bloodQA;
	QueueUnitBlood *bloodQB;
	ScientificResearchProcess *scProcA;
	ScientificResearchProcess *scProcB;
	UtilizationProcess *utilizationDonorProcA;
	UtilizationProcess *utilizationOrderProcA;
	UtilizationProcess *utilizationSpecialOrderProcA;
	UtilizationProcess *utilizationDonorProcB;
	UtilizationProcess *utilizationOrderProcB;
	UtilizationProcess *utilizationSpecialOrderProcB;
	RecipientProcess *recProcess;
};

