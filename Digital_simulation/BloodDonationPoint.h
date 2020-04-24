#pragma once
class BloodDonationPoint
{
public:
	int getClock() const;
	void setClock(int newClock);
	void setAmountBloodA(int);
	int getAmountBloodA();
	void setAmountBloodB(int);
	int getAmountBloodB();
	void setMinAmountBlood(int);
	int getMinAMountBlood();
	void setTimeOfUseBloodFromOrder(int);
	int getTimeOfUseBloodFromOrder();
	void setTimeOfUseBloodFromDonor(int);
	int getTimeOfUseBloodFromDonor();
	void setMaxTimeOfSimulation(int);
	int getMaxTimeOfSimulation();
	void incrementAmoutnOfIteracions();
	int getAmountOfIteracions();
	void clearAmountOfIteracions();
	void setOrderFlagA();
	void clearOrderFlagA();
	bool checkOrderFlagA();
	void setSpecialOrderFlagA();
	void clearSpecialOrderFlagA();
	bool checkSpecialOrderFlagA();
	void setOrderFlagB();
	void clearOrderFlagB();
	bool checkOrderFlagB();
	void setSpecialOrderFlagB();
	void clearSpecialOrderFlagB();
	bool checkSpecialOrderFlagB();
	BloodDonationPoint();
	~BloodDonationPoint();
private:
	int clock;
	int amountBloodA;
	int amountBloodB;
	int minAmountBlood;
	int timeOfUseBloodFromOrder;
	int timeOfUseBloodFromDonor;
	int maxTimeOfSimulation;
	bool orderFlagA;
	bool specialOrderFlagA;
	bool orderFlagB;
	bool specialOrderFlagB;
	int amountOfIteracions;
};

