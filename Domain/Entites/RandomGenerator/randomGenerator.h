#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include "../../../lib.h"
#include "../../../Core/core.h"

class RandomGenerator
{
public:
	static double generateNumber(double min, double max);
	static long long generateNumber(long long min, long long max);
};

#endif