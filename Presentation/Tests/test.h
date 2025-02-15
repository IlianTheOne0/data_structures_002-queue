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
	static void jobTest();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { queueTest(); } break;
			case 1: { jobTest(); } break;
			default: { View::Intro0(); }
		}
	}
};

#endif