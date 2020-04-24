#pragma once
#include <cstdint>
#include "Generators.h"
#include "BloodDonationPoint.h"

class GeneratorTest
{
	uint32_t samples;
	const uint64_t m = 2147483647;
	const uint64_t a = 16807;
	uint64_t grain = 0;
	Generators *specialOrder;
	Generators *normalOrder;
	Generators *recipientComing;
	Generators *donorComing;
	Generators *neededBloodGeometric;
	Generators *campaingUniform;
	Generators *timeDonorUniform;
	BloodDonationPoint *bPoint;
public:
	uint64_t generateGrain(uint64_t,uint64_t);
	void testNormal(int);
	void testUniform(int);
	void testGeometric(int);
	void testExpotentional(int);
	GeneratorTest(uint32_t,BloodDonationPoint *bP);
	~GeneratorTest();
};

