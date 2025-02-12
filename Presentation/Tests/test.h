#ifndef TEST_H
#define TEST_H

#include "../../Core/core.h"
#include "../../lib.h"
#include "../View/view.h"

class Test
{
private:
	static const unsigned short testCounter;
public:
	static void passengerTest();
	static void queueTest();
	static void busStopTest();
	static void randomGeneratorTest();
	static void eventHandlerTest();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { passengerTest(); } break;
			case 1: { queueTest(); } break;
			case 2: { busStopTest(); } break;
			case 3: { randomGeneratorTest(); } break;
			case 4: { eventHandlerTest(); } break;
			default: { View::Intro0(); }
		}
	}
};

#endif