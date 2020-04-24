#include "pch.h"
#include "Statistics.h"
#include <iostream>
#include <fstream>

using namespace std;

void Statistics::viewStat()
{
	cout << "Statystyki:" << endl;
	cout << "N - nowych zamowienien (standardowe zamowienie) = " << orderProcA->getAmountOfOrder() << endl;
	cout << "R - prog zamawiania = " << bloodPoint->getMinAMountBlood() << endl << endl;
	cout << "Krew przechodzaca przez punkt = " << bloodQA->getAmoutnOfBloodStatistics() + bloodQB->getAmoutnOfBloodStatistics() << endl;
	cout << "Krew przechodzaca przez punkt gr.A = " << bloodQA->getAmoutnOfBloodStatistics()<< endl;
	cout << "Krew przechodzaca przez punkt gr.B = " << bloodQB->getAmoutnOfBloodStatistics() << endl;
	cout << "Krew przechodzaca przez punkt gr.A % = " << bloodQA->getAmoutnOfBloodStatistics()*100/(bloodQA->getAmoutnOfBloodStatistics() 
		+ bloodQB->getAmoutnOfBloodStatistics()) << endl;
	cout << "Krew przechodzaca przez punkt gr.B % = " << bloodQB->getAmoutnOfBloodStatistics()*100 / (bloodQA->getAmoutnOfBloodStatistics()
		+ bloodQB->getAmoutnOfBloodStatistics()) << endl;
	cout << "Zuzyta krew przez pacjentow = " << recProcess->getBloodPacientStatistics() << endl;
	cout << "Krew wyslana na badania naukowe = " << scProcA->getAmountOfBloodStatistic() + scProcB->getAmountOfBloodStatistic() << endl;
	cout << "Krew wyslana na badania naukowe gr.A = " << scProcA->getAmountOfBloodStatistic() << endl;
	cout << "Krew wyslana na badania naukowe gr.B= " << scProcB->getAmountOfBloodStatistic() << endl;
	cout << "Srednia liczba jednostek krwi w kolejce = " << ((double)bloodQA->getAmoutnOfBloodStatistics() + bloodQA->getAmoutnOfBloodStatistics()) /
		bloodPoint->getAmountOfIteracions() << endl;
	int utilizeBlood = utilizationDonorProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcA->getAmountOfUtilizeBloodStatistics() + utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationDonorProcB->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcB->getAmountOfUtilizeBloodStatistics() + utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics();
	cout << "Zutylizowana krew = " << utilizeBlood << endl;
	cout << "Zutylizowana krew z normalnego zamowienia = " << utilizationOrderProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcB->getAmountOfUtilizeBloodStatistics() << endl;
	cout << "Zutylizowana krew ze specjalneg zamowienia = " << utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics() << endl;
	cout << "Zutylizowana krew od dawcow = " << utilizationDonorProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationDonorProcB->getAmountOfUtilizeBloodStatistics() << endl;
	cout << "Procent zutylizowanej krwi = " << (double)utilizeBlood * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
		bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	cout << "Procent zutylizowanej krwi z normalnego zamowienia = " << ((double)utilizationOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationOrderProcB->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	cout << "Procent zutylizowanej krwi ze specjalnego zamowienia = " << ((double)utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	cout << "Procent zutylizowanej krwi od dawcow = " << ((double)utilizationDonorProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationDonorProcA->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	cout << "Pacjentow przechodzacych przez punkt = " << recipientQA->getAmountOfPatientStatistics() +
		recipientQB->getAmountOfPatientStatistics() << endl;
	cout << "Srednia liczba pacjentow w kolejce = " << ((double)recipientQA->getAmountOfPatientStatistics() +
		recipientQB->getAmountOfPatientStatistics()) / bloodPoint->getAmountOfIteracions() << endl;
	cout << "Liczba normalnych zamowien = " << orderProcA->getOrderID() + orderProcB->getOrderID()<< endl;
	cout << "Liczba specialnych zamowien = " << recProcess->getSpecialOrderID() << endl;
	cout << "Prawdopodobienstwo wystapienia awaryjnego zamowienia = " << (double)recProcess->getSpecialOrderID() * 100 /
		bloodPoint->getAmountOfIteracions() << "%" << endl;
	cout << endl << endl;
}

void Statistics::printToFile()
{
	ofstream stat;
	stat.open("satistics.txt", ios::out | ios::app);
	stat << endl;
	stat << "Statystyki:" << endl;
	stat << "N - nowych zamowienien (standardowe zamowienie) = " << orderProcA->getAmountOfOrder() << endl;
	stat << "R - prog zamawiania = " << bloodPoint->getMinAMountBlood() << endl << endl;
	stat << "Krew przechodzaca przez punkt = " << bloodQA->getAmoutnOfBloodStatistics() + bloodQB->getAmoutnOfBloodStatistics() << endl;
	stat << "Krew przechodzaca przez punkt gr.A = " << bloodQA->getAmoutnOfBloodStatistics() << endl;
	stat << "Krew przechodzaca przez punkt gr.B = " << bloodQB->getAmoutnOfBloodStatistics() << endl;
	stat << "Krew przechodzaca przez punkt gr.A % = " << bloodQA->getAmoutnOfBloodStatistics() * 100 / (bloodQA->getAmoutnOfBloodStatistics()
		+ bloodQB->getAmoutnOfBloodStatistics()) << endl;
	stat << "Krew przechodzaca przez punkt gr.B % = " << bloodQB->getAmoutnOfBloodStatistics() * 100 / (bloodQA->getAmoutnOfBloodStatistics()
		+ bloodQB->getAmoutnOfBloodStatistics()) << endl;
	stat << "Zuzyta krew przez pacjentow = " << recProcess->getBloodPacientStatistics() << endl;
	stat << "Krew wyslana na badania naukowe = " << scProcA->getAmountOfBloodStatistic() + scProcB->getAmountOfBloodStatistic() << endl;
	stat << "Krew wyslana na badania naukowe gr.A = " << scProcA->getAmountOfBloodStatistic() << endl;
	stat << "Krew wyslana na badania naukowe gr.B= " << scProcB->getAmountOfBloodStatistic() << endl;
	stat << "Srednia liczba jednostek krwi w kolejce = " << ((double)bloodQA->getAmoutnOfBloodStatistics() + bloodQA->getAmoutnOfBloodStatistics()) /
		bloodPoint->getAmountOfIteracions() << endl;
	int utilizeBlood = utilizationDonorProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcA->getAmountOfUtilizeBloodStatistics() + utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationDonorProcB->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcB->getAmountOfUtilizeBloodStatistics() + utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics();
	stat << "Zutylizowana krew = " << utilizeBlood << endl;
	stat << "Zutylizowana krew z normalnego zamowienia = " << utilizationOrderProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationOrderProcB->getAmountOfUtilizeBloodStatistics() << endl;
	stat << "Zutylizowana krew ze specjalneg zamowienia = " << utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics() << endl;
	stat << "Zutylizowana krew od dawcow = " << utilizationDonorProcA->getAmountOfUtilizeBloodStatistics() +
		utilizationDonorProcB->getAmountOfUtilizeBloodStatistics() << endl;
	stat << "Procent zutylizowanej krwi = " << (double)utilizeBlood * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
		bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	stat << "Procent zutylizowanej krwi z normalnego zamowienia = " << ((double)utilizationOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationOrderProcB->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	stat << "Procent zutylizowanej krwi ze specjalnego zamowienia = " << ((double)utilizationSpecialOrderProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationSpecialOrderProcB->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	stat << "Procent zutylizowanej krwi od dawcow = " << ((double)utilizationDonorProcA->getAmountOfUtilizeBloodStatistics()
		+ utilizationDonorProcA->getAmountOfUtilizeBloodStatistics()) * 100 / (bloodQA->getAmoutnOfBloodStatistics() +
			bloodQB->getAmoutnOfBloodStatistics()) << "%" << endl;
	stat << "Pacjentow przechodzacych przez punkt = " << recipientQA->getAmountOfPatientStatistics() +
		recipientQB->getAmountOfPatientStatistics() << endl;
	stat << "Srednia liczba pacjentow w kolejce = " << ((double)recipientQA->getAmountOfPatientStatistics() +
		recipientQB->getAmountOfPatientStatistics()) / bloodPoint->getAmountOfIteracions() << endl;
	stat << "Liczba normalnych zamowien = " << orderProcA->getOrderID() + orderProcB->getOrderID() << endl;
	stat << "Liczba specialnych zamowien = " << recProcess->getSpecialOrderID() << endl;
	stat << "Prawdopodobienstwo wystapienia awaryjnego zamowienia = " << (double)recProcess->getSpecialOrderID() * 100 /
		bloodPoint->getAmountOfIteracions() << "%" << endl;
	stat << endl << endl;
	stat.close();
}

void Statistics::saveStatsToFile(double data, string name)
{
	ofstream result;
	result.open(name, ios::out | ios::app);
	result << data << endl;
	result.close();
}

void Statistics::saveStatsToFile2(double data, int time, string name)
{
	ofstream result;
	result.open(name, ios::out | ios::app);
	result << data << "    " << time<< endl;
	result.close();
}

Statistics::Statistics(BloodDonationPoint *bPoint, DonorProcess *dProc, OrderProcess *orderPA, OrderProcess *orderPB,
	QueueRecipient *recQA, QueueRecipient *recQB,QueueUnitBlood *bQA, QueueUnitBlood *bQB, ScientificResearchProcess *scPA,
	ScientificResearchProcess *scPB, UtilizationProcess *utilizationDonorA, UtilizationProcess *utilizationOrderA,
	UtilizationProcess *utilizationSpecialOrderA, UtilizationProcess *utilizationDonorB, UtilizationProcess *utilizationOrderB,
	UtilizationProcess *utilizationSpecialOrderB, RecipientProcess *recPr)
	:bloodPoint(bPoint), dProcess(dProc), orderProcA(orderPA), orderProcB(orderPB),
	recipientQA(recQA), recipientQB(recQB), bloodQA(bQA), bloodQB(bQB), scProcA(scPA), scProcB(scPB), utilizationDonorProcA(utilizationDonorA),
	utilizationDonorProcB(utilizationDonorB), utilizationOrderProcA(utilizationOrderA),utilizationOrderProcB(utilizationOrderB),
	utilizationSpecialOrderProcA(utilizationSpecialOrderA), utilizationSpecialOrderProcB(utilizationSpecialOrderB), recProcess(recPr)
{
}

Statistics::Statistics()
{
}


Statistics::~Statistics()
{
}
