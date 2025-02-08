#ifndef TEST_H
#define TEST_H

#include "../../Core/core.h"
#include "../../lib.h"

class Test
{
private:
	static const unsigned short testCounter;
public:
	static void Test0();

	static void startTest()
	{
		switch (testCounter)
		{
			case 0: { Test0(); } break;
		}
	}
};

#endif