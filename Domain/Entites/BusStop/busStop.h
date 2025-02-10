#ifndef BUSSTOP_H
#define BUSSTOP_H

#include "busStopAbstraction.h"

class BusStop
	: public ABusStop
{
public:
	BusStop() = delete;
	BusStop(bool isTreminal);
	~BusStop() override;
};

#endif