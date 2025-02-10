#include "randomGenerator.h"

long long RandomGenerator::generateNumber(long long min, long long max)
{
	INFO("RandomGenerator -> static method generateNumber: called;");

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<long long> dist(min, max);

	return dist(gen);
}