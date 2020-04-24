#include "pch.h"
#include "DonorProcess.h"
#include <iostream>

using namespace std;

void DonorProcess::execute()
{
	cout << "'DonorProcess': Obsluga dawcy" << endl;
	int clock = bloodPoint->getClock();
	UnitBlood *blood = new UnitBlood(clock + bloodPoint->getTimeOfUseBloodFromDonor());
	queueBlood->addBlood(blood);
	cout << "- dodanie jednostki krwi do kolejki krwi" << endl;
	activate(timeOfComingDonorExponential_850);
	cout << "- zaplanowanie kolejnego procesu 'DonorProcess'" << endl;
	uProcess->setHowManyToRemove(1);
	uProcess->activate(bloodPoint->getTimeOfUseBloodFromDonor());
	cout << "- zaplanowanie usuniecia jednostki krwi 'UtilizationProcess'" << endl;
	bool group = blood->showGroup();
	recipientProcess->reactive(group);
}

void DonorProcess::setTimeOfComingDonorExponential_850(int number)
{
	timeOfComingDonorExponential_850 = number;
}


DonorProcess::DonorProcess(BloodDonationPoint *bPoint, EventList *el, QueueUnitBlood *qBlood, UtilizationProcess *uP,
	RecipientProcess *rProcess)
	: Process(bPoint, el, qBlood), uProcess(uP), recipientProcess(rProcess)
{

}

DonorProcess::~DonorProcess()
{
}
