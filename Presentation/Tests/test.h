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
	static void queueTest();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { queueTest(); } break;
			default: { View::Intro0(); }
		}
	}
};

#endif