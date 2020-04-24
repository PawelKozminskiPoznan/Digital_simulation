#pragma once

class Generators
{
	
	int m;
	int a;
	int q;
	int r;
public:
	int grain;
	double generateGrain();
	double uniform();
	int generateExponentinal(double lambda);
	int generateGeometric(double average);
	int generateNormal(int average,double var);
	int generateUniform(int min,int max);
	/*void testGenerateExponentinal(double lambda, int samples);
	void testGenerateGeometric(double w, int samples);
	void testGenerateNormal(const double e, const double ew, const int samples);
	void testGenerateUniform(int min, int max,int samples);*/
	Generators();//Statistics *s
	~Generators();
};

