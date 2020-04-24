#include "pch.h"
#include "Generators.h"
#include <iostream>

using namespace std;


double Generators::generateGrain()
{
	int h =abs(grain / q);
	grain = a * (grain - q * h) - r * h;
	if (grain < 0)
		grain = grain + m;
	return grain;
}


double Generators::uniform()
{
	grain = grain * a % m;
	return abs(static_cast<double>(grain)/m);
}

int Generators::generateUniform(const int min,const int max)
{
	return (int)uniform()*(max - min) + min;
}

int Generators::generateNormal(int average, double var)
{
	double k = 0;
	for(int i=0;i<12;i++)
	{
		k += uniform();
	}
	k = k - 6;
	k = sqrt(var)*k + average;
	return (int)k;
}

int Generators::generateExponentinal(double lambda)
{
	lambda = 1 / lambda;
	return (int)(-(1.0 / lambda)*log(uniform()));
}

int Generators::generateGeometric(double average)
{
	int k = 1;
	/*
	while (uniform()>average)
	{
		++k;
	}
	return k;
	*/
	while (true)
	{
		if (uniform() > average)
		{
			k++;
			continue;
		}
		break;
	}
	return k;
}
/*
void Generators::testGenerateExponentinal(double lambda,int samples)
{
	double average = 0;
	int result;
	lambda = 1 / lambda;
	cout << "Start Test Exponential Generator." << endl;
	for (int i = 0; i < samples; ++i) {
		result = -1 / lambda * log(uniform());

		stat->saveStatsToFile(result, "exponential.xls");         
		average = average + result;
	}

	cout << "average : " << average / samples << endl;
}

void Generators::testGenerateGeometric(double w,int samples)
{
	cout << "Start Test Geometric Generator." << endl;
	double ave = 0;
	int result;
	for (auto i = 0; i < samples; ++i) {
		result = 1;
		while (true)
		{
			if (uniform() > w)
			{ 
				result++;
				continue;
			}             
			break;
		}

		stat->saveStatsToFile(result, "geometric.xls");         
		ave = ave + result;
	}

	cout << "w : " << 1 / (ave / samples) << endl;
	cout << "average : " << double(ave / samples) << endl;
}

void Generators::testGenerateNormal(const double e, const double ew, const int samples)
{
	cout << "Start Test Normal Generator." << endl;
	double average = 0;
	int result;
	for (auto i = 0; i < samples; ++i)
	{
		result = 0;
		double temp = 0;
		for (auto index = 0; index < 12; index++)
		{
			temp += uniform();
		}
		temp -= 6.0;
		result= temp * ew + e;

		stat->saveStatsToFile(result, "normal.xls");         
		average = average + result;
	}

	cout << "average : " << average / samples << endl;
}

void Generators::testGenerateUniform(int min, int max,int samples)
{
	double average = 0;
	double numberUniform = 0;
	cout << "Start Test Uniform Generator." << endl;
	generateGrain();
	for (auto i = 0; i < samples; ++i)
	{
		numberUniform = min + (max - min) * uniform();
		stat->saveStatsToFile(numberUniform, "uniform.xls");         
		average = average + numberUniform;
	}
	cout << "average : " << average / samples << endl;
}
*/
Generators::Generators()//Statistics *s :stat(s)
{
	m = 2147483647;
	a = 16807;
	q = 127773;
	r = 2836;
	grain = 1179;
}


Generators::~Generators()
{
}
