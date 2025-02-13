#include "busStop.h"

BusStop::BusStop(bool isTerminal, unsigned short maxQueueLength)
	: ABusStop(isTerminal, maxQueueLength)
{ CREATE_INFO("BusStop <- Constructor: called;"); }
BusStop::~BusStop() { CREATE_INFO("BusStop <- Destructor: called;"); }