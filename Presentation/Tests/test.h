#ifndef TEST_H
#define TEST_H

#include "../../Core/core.h"
#include "../../lib.h"

class Test
{
private:
	static const unsigned short testCounter;
public:
	static void passengerTest();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { passengerTest(); } break;
		}
	}
};

#endif