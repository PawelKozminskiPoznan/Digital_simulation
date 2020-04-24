#include "pch.h"
#include "BloodDonationPoint.h"

int BloodDonationPoint::getClock() const
{
	return clock;
}

void BloodDonationPoint::setClock(int newClock)
{
	clock = newClock;
}

void BloodDonationPoint::setAmountBloodA(int amout)
{
	amountBloodA = amout;
}

int BloodDonationPoint::getAmountBloodA()
{
	return amountBloodA;
}

void BloodDonationPoint::setAmountBloodB(int number)
{
	amountBloodB = number;
}
int BloodDonationPoint::getAmountBloodB()
{
	return amountBloodB;
}

void BloodDonationPoint::setMinAmountBlood(int amount)
{
	minAmountBlood = amount;
}

int BloodDonationPoint::getMinAMountBlood()
{
	return minAmountBlood;
}

void BloodDonationPoint::setTimeOfUseBloodFromOrder(int number)
{
	timeOfUseBloodFromOrder = number;
}

int BloodDonationPoint::getTimeOfUseBloodFromOrder()
{
	return timeOfUseBloodFromOrder;
}

void BloodDonationPoint::setTimeOfUseBloodFromDonor(int number)
{
	timeOfUseBloodFromDonor = number;
}

int BloodDonationPoint::getTimeOfUseBloodFromDonor()
{
	return timeOfUseBloodFromDonor;
}

void BloodDonationPoint::setMaxTimeOfSimulation(int number)
{
	maxTimeOfSimulation = number;
}
int BloodDonationPoint::getMaxTimeOfSimulation()
{
	return maxTimeOfSimulation;
}

void BloodDonationPoint::incrementAmoutnOfIteracions()
{
	amountOfIteracions++;
}
int BloodDonationPoint::getAmountOfIteracions()
{
	return amountOfIteracions;
}

void BloodDonationPoint::setOrderFlagA()
{
	orderFlagA = true;
}

void BloodDonationPoint::clearOrderFlagA()
{
	orderFlagA = false;
}

bool BloodDonationPoint::checkOrderFlagA()
{
	return orderFlagA;
}

void BloodDonationPoint::setSpecialOrderFlagA()
{
	specialOrderFlagA = true;
}

void BloodDonationPoint::clearSpecialOrderFlagA()
{
	specialOrderFlagA = false;
}

bool BloodDonationPoint::checkSpecialOrderFlagA()
{
	return specialOrderFlagA;
}

void BloodDonationPoint::setOrderFlagB()
{
	orderFlagB = true;
}

void BloodDonationPoint::clearOrderFlagB()
{
	orderFlagB = false;
}

bool BloodDonationPoint::checkOrderFlagB()
{
	return orderFlagB;
}

void BloodDonationPoint::setSpecialOrderFlagB()
{
	specialOrderFlagB = true;
}

void BloodDonationPoint::clearSpecialOrderFlagB()
{
	specialOrderFlagB = false;
}

bool BloodDonationPoint::checkSpecialOrderFlagB()
{
	return specialOrderFlagB;
}


void BloodDonationPoint::clearAmountOfIteracions()
{
	amountOfIteracions = 0;
}

BloodDonationPoint::BloodDonationPoint()
{
	clock = 0;
	amountBloodA = 0;
	amountBloodB = 0;
	minAmountBlood = 10;
	timeOfUseBloodFromOrder = 300;
	timeOfUseBloodFromDonor = 500;
	amountOfIteracions = 0;
	maxTimeOfSimulation = 1000;
	orderFlagA = false;
	specialOrderFlagA= false;
	orderFlagB = false;
	specialOrderFlagB = false;
}

BloodDonationPoint::~BloodDonationPoint()
{
}
