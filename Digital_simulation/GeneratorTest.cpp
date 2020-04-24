#include "pch.h"
#include "GeneratorTest.h"
#include <iostream>
#include <fstream>

using namespace std;

GeneratorTest::GeneratorTest(uint32_t test,BloodDonationPoint *bP)
{
	bPoint = bP;
	samples = test;
	cout << "Testowanie generatorow." << endl;
	/*specialOrder = new Generators(6 + (bPoint->getClock()+1)*8);
	normalOrder = new Generators(2 + (bPoint->getClock())*8);
	recipientComing = new Generators(3 + (bPoint->getClock()+3)*8);
	donorComing = new Generators(1 + (bPoint->getClock()+4)*8);
	neededBloodGeometric = new Generators(4 + (bPoint->getClock()+5)*8);
	campaingUniform = new Generators(5 + (bPoint->getClock()+6)*8);
	timeDonorUniform = new Generators(8 + (bPoint->getClock()+7)*8);*/

	testExpotentional(test);
	testNormal(test);
	testGeometric(test);
	testUniform(test);

	cout << "Wygenerowano test." << endl;
}

void GeneratorTest::testExpotentional(int samples2)
{
	double PLambda = 1.0 / 200;
	double LLambda = 1.0 / 850;
	double ZLambda = 1.0 / 1900;
	ofstream result;

	/*result.open("expotentional.xls", ios::out | ios::app);
	result << endl << endl << "Zamowienie normalne czas: " << Generators::kernels[(2 + (bPoint->getClock() ) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << normalOrder->generateExpotentional(ZLambda) << "      " << normalOrder->generateKernel();
	result.close();

	result.open("expotentional.xls", ios::out | ios::app);
	result << endl << endl << "Pacjent czas: " << Generators::kernels[(3 + (bPoint->getClock() + 3) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << recipientComing->generateExpotentional(PLambda) << "      " << recipientComing->generateKernel();
	result.close();

	result.open("expotentional.xls", ios::out | ios::app);
	result << endl << endl << "Dawca czas: " << Generators::kernels[(1 + (bPoint->getClock() + 4) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << donorComing->generateExpotentional(LLambda) << "      " << donorComing->generateKernel();
	result.close();*/
}

void GeneratorTest::testNormal(int samples2)
{
	/*double ew2 = 0.1;
	uint16_t e = 400;

	ofstream result;

	result.open("normal.xls", ios::out | ios::app);
	result << endl << endl << "Zamowienie awaryjne czas: " << Generators::kernels[(6 + (bPoint->getClock() + 1) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << specialOrder->generateNormal(e,ew2) << "      " << specialOrder->generateKernel();
	result.close();*/
}

void GeneratorTest::testUniform(int samples2)
{
	uint16_t tw_min = 20000;
	uint16_t tw_max = 22000;
	uint8_t tk_min = 100;
	uint8_t tk_max = 200;

	ofstream result;

	/*result.open("uniform.xls", ios::out | ios::app);
	result << endl << endl << "Uniform: " << Generators::kernels[(5 + (bPoint->getClock() + 6) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << campaingUniform->generateUniform(tw_min,tw_max) << "      " << campaingUniform->generateKernel();
	result.close();*/
}

void GeneratorTest::testGeometric(int samples2)
{
	double w = 0.23;

	ofstream result;
	/*result.open("geometric.xls", ios::out | ios::app);
	result << endl << endl << "Potrzebna krew: " << Generators::kernels[(4 + (bPoint->getClock() + 5) * 8)] << endl;
	for (int i = 0; i < samples2; i++)
		result << endl << neededBloodGeometric->generateGeometric(w) << "      " << neededBloodGeometric->generateKernel();
	result.close();*/
}

uint64_t GeneratorTest::generateGrain(uint64_t grainN, uint64_t sampleN)
{
	grain = grainN;
	for(uint64_t i =0;i<sampleN;i++ )
	{
		grain = grain * a % m ;
	}
	return grain;
}


GeneratorTest::~GeneratorTest()
{
}
