#include "busStop.h"

BusStop::BusStop(bool isTerminal)
	: ABusStop(isTerminal)
{
	CREATE_INFO("BusStop <- Constructor: called;");
}
BusStop::~BusStop() { CREATE_INFO("BusStop <- Destructor: called;"); }