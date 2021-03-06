#include "pch.h"
#include <iostream>
#include "Event.h"
#include "Process.h"
#include "EventList.h"
#include "QueueRecipient.h"
#include "QueueUnitBlood.h"
#include "DonorProcess.h"
#include "RecipientProcess.h"
#include "OrderSpecialProcess.h"
#include "OrderProcess.h"
#include "ScientificResearchProcess.h"
#include "Statistics.h"
#include "Generators.h"

using namespace std;

int main()
{
	int amountOfSimulation;
	cout << "Liczba symulacji : ";
	cin >> amountOfSimulation;
	Generators *generator = new Generators();
	for (int i = 0; i < amountOfSimulation; i++)
	{
		BloodDonationPoint *bPoint = new BloodDonationPoint();
		bPoint->setMaxTimeOfSimulation(60000);// max czas symulacji
		bPoint->setMinAmountBlood(5); //prog R
		bPoint->setTimeOfUseBloodFromOrder(600); //czas przydatnosci krwi z zamowien T1
		bPoint->setTimeOfUseBloodFromDonor(600); //czas przydatnoci krwi od dawcy T2
		EventList *eList = new EventList();
		QueueUnitBlood *bloodQueueA = new QueueUnitBlood();
		QueueUnitBlood *bloodQueueB = new QueueUnitBlood();
		bloodQueueA->setBloodDonationPoint(bPoint);
		bloodQueueB->setBloodDonationPoint(bPoint);
		QueueRecipient *recipientQueueA = new QueueRecipient();
		recipientQueueA->setBloodDonationPoint(bPoint);
		QueueRecipient *recipientQueueB = new QueueRecipient();
		recipientQueueB->setBloodDonationPoint(bPoint);
		UtilizationProcess *donorUtilizationA = new UtilizationProcess(bPoint, eList, bloodQueueA);
		UtilizationProcess *donorUtilizationB = new UtilizationProcess(bPoint, eList, bloodQueueB);
		UtilizationProcess *orderUtilizationA = new UtilizationProcess(bPoint, eList, bloodQueueA);
		UtilizationProcess *orderUtilizationB = new UtilizationProcess(bPoint, eList, bloodQueueB);
		UtilizationProcess *specialOrderUtilizationA = new UtilizationProcess(bPoint, eList, bloodQueueA);
		UtilizationProcess *specialOrderUtilizationB = new UtilizationProcess(bPoint, eList, bloodQueueB);
		ScientificResearchProcess *scResearchProcessA = new ScientificResearchProcess(bPoint, eList, bloodQueueA);
		ScientificResearchProcess *scResearchProcessB = new ScientificResearchProcess(bPoint, eList, bloodQueueB);
		scResearchProcessA->bloodPoint = bPoint;
		scResearchProcessA->eList = eList;
		scResearchProcessA->queueBlood = bloodQueueA;
		scResearchProcessB->bloodPoint = bPoint;
		scResearchProcessB->eList = eList;
		scResearchProcessB->queueBlood = bloodQueueB;
		RecipientProcess *recipientProcess = new RecipientProcess(bPoint, eList, bloodQueueA, bloodQueueB, recipientQueueA,
			recipientQueueB,scResearchProcessA, scResearchProcessB);
		OrderSpecialProcess *specialOrderProcessA = new OrderSpecialProcess(bPoint, eList, bloodQueueA, specialOrderUtilizationA,
			recipientProcess, scResearchProcessA,false);
		OrderSpecialProcess *specialOrderProcessB = new OrderSpecialProcess(bPoint, eList, bloodQueueB, specialOrderUtilizationB,
			recipientProcess, scResearchProcessB,true);
		specialOrderProcessA->setAmountOfSpecialOrder(30); // liczba Q zamowionej krwi - specjalne zamówienie
		specialOrderProcessB->setAmountOfSpecialOrder(30);
		recipientProcess->setSpecialOrderA(specialOrderProcessA);
		recipientProcess->setSpecialOrderB(specialOrderProcessB);
		OrderProcess *orderProcessA = new OrderProcess(bPoint, eList, bloodQueueA, orderUtilizationA, recipientProcess, scResearchProcessA,false);
		OrderProcess *orderProcessB = new OrderProcess(bPoint, eList, bloodQueueB, orderUtilizationB, recipientProcess, scResearchProcessB,true);
		orderProcessA->setAmountOfOrder(35); // liczba N zamowionej krwi - normalne zamowienie
		orderProcessB->setAmountOfOrder(35);
		recipientProcess->setOrderA(orderProcessA);
		recipientProcess->setOrderB(orderProcessB);
		DonorProcess *donorProcess = new DonorProcess(bPoint, eList, bloodQueueA, donorUtilizationA, recipientProcess);
		Statistics *statSimulation = new Statistics(bPoint, donorProcess, orderProcessA, orderProcessB, recipientQueueA, recipientQueueB,
			bloodQueueA, bloodQueueB, scResearchProcessA,scResearchProcessB, donorUtilizationA, donorUtilizationB,
			orderUtilizationA, orderUtilizationB, specialOrderUtilizationA, specialOrderUtilizationB, recipientProcess);
		recipientProcess->setNeededBloodGeometric_0_23(generator->generateGeometric(0.23));
		recipientProcess->setTimeOfOrderExponential_1900(generator->generateExponentinal(1900));
		recipientProcess->setTimeOfRecipientExponential_200(generator->generateExponentinal(200));
		recipientProcess->setTimeOfSpecialOrderNormal_400(generator->generateNormal(400, 0.1));
		donorProcess->setTimeOfComingDonorExponential_850(generator->generateExponentinal(850));
		scResearchProcessA->setAmountOfBloodUniform_5_10(generator->generateUniform(5, 10));
		scResearchProcessB->setAmountOfBloodUniform_5_10(generator->generateUniform(5, 10));
		Process *wskProcess = nullptr;
		donorProcess->activate(30);
		recipientProcess->activate(20);
		cout << "Tryb pracy symulacji:" << endl;
		cout << "Wybierz : 0.Ciaglym" << endl;
		cout << "Wybierz : 1.Krokowy" << endl;
		bool mode;
		char a;
		cin >> a;
		if (a == '1')
			mode = true;
		else
			mode = false;
		cout << endl << endl;
		bool beginingPhase = false;
		while (bPoint->getClock() < bPoint->getMaxTimeOfSimulation())
		{
			if(bPoint->getClock() > 10000 && !beginingPhase )
			{
				beginingPhase = true;
				bloodQueueA->clearAmountOfBloodStatistics();
				bloodQueueB->clearAmountOfBloodStatistics();
				recipientProcess->clearBloodPacientStatistics();
				recipientProcess->clearSpecialOrderID();
				scResearchProcessA->clearAmountOfBloodStatistic();
				scResearchProcessB->clearAmountOfBloodStatistic();
				bPoint->clearAmountOfIteracions();
				donorUtilizationA->clearAmountOfUtilizeBloodStatistics();
				orderUtilizationA->clearAmountOfUtilizeBloodStatistics();
				specialOrderUtilizationA->clearAmountOfUtilizeBloodStatistics();
				donorUtilizationB->clearAmountOfUtilizeBloodStatistics();
				orderUtilizationB->clearAmountOfUtilizeBloodStatistics();
				specialOrderUtilizationB->clearAmountOfUtilizeBloodStatistics();
				orderProcessA->clearOrderID();
				orderProcessB->clearOrderID();
				recipientQueueA->clearAmountOfPatientStatistics();
				recipientQueueB->clearAmountOfPatientStatistics();
			}
			for (int i = 0; i < 6 * generator->uniform(); i++)
			{
				generator->generateGrain();
			}
			recipientProcess->setNeededBloodGeometric_0_23(generator->generateGeometric(0.23));
			recipientProcess->setTimeOfOrderExponential_1900(generator->generateExponentinal(1900));
			recipientProcess->setTimeOfRecipientExponential_200(generator->generateExponentinal(200));
			recipientProcess->setTimeOfSpecialOrderNormal_400(generator->generateNormal(400, 0.1));
			donorProcess->setTimeOfComingDonorExponential_850(generator->generateExponentinal(850));
			scResearchProcessA->setAmountOfBloodUniform_5_10(generator->generateUniform(5, 10));
			scResearchProcessB->setAmountOfBloodUniform_5_10(generator->generateUniform(5, 10));
			bPoint->setClock(eList->getFirstTime());
			if (bPoint->getClock() < bPoint->getMaxTimeOfSimulation())
			{
				cout << "Czas symulacji: " << bPoint->getClock() << endl;
				wskProcess = eList->getFirstEvent()->getProcess();
				eList->removeEvent();// usuwamy z listy zdarzeń przed metodą execute() -bo ona dodaje to samo zdarzenie do listy zdarzeń
				wskProcess->execute();
				cout << "Liczba pacjentow w kolejce gr A: " << recipientQueueA->howManyRecipients() << endl;
				cout << "Liczba pacjentow w kolejce gr B: " << recipientQueueB->howManyRecipients() << endl;
				cout << "Liczba jednostek krwi gr A: " << bPoint->getAmountBloodA() << endl;
				cout << "Liczba jednostek krwi gr B: " << bPoint->getAmountBloodB() << endl;
				cout << endl;
				if (mode)
				{
					cout << "Tryb pracy symulacji:" << endl;
					cout << "Wybierz : 0.Ciaglym" << endl;
					cout << "Wybierz : Enter.Krokowy" << endl;
					int a = getchar();
					if (a != 10)
						mode = false;
					else
						mode = true;
					cout << endl << endl << endl;
				}
			}
			bPoint->incrementAmoutnOfIteracions();
		}
		statSimulation->viewStat();
		statSimulation->printToFile();
		delete bPoint;
		delete eList;
		delete bloodQueueA;
		delete bloodQueueB;
		delete recipientQueueA;
		delete recipientQueueB;
		delete donorUtilizationA;
		delete donorUtilizationB;
		delete orderUtilizationA;
		delete orderUtilizationB;
		delete specialOrderUtilizationA;
		delete specialOrderUtilizationB;
		delete scResearchProcessA;
		delete scResearchProcessB;
		delete recipientProcess;
		delete specialOrderProcessA;
		delete specialOrderProcessB;
		delete orderProcessA;
		delete orderProcessB;
		delete donorProcess;
		delete statSimulation;
	}
}

