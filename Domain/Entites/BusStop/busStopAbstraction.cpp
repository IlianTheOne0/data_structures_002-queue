#include "busStopAbstraction.h"

void ABusStop::setIsTerminal(const bool& value) {INFO("ABusStop -> method setIsTerminal: called;"); _isTerminal = value; }
void ABusStop::setTotalPassengers(const unsigned short& value) {INFO("ABusStop -> method setTotalPassengers: called;"); _totalPassengers = value; }
void ABusStop::setTotalWaitTime(const double& value) {INFO("ABusStop -> method setTotalWaitTime: called;"); _totalWaitTime = value; }

ABusStop::ABusStop(bool isTerminal)
	: _isTerminal(isTerminal)
{ CREATE_INFO("ABusStop <- Constructor: called;"); }
ABusStop::~ABusStop() { CREATE_INFO("ABusStop <- Destructor: called;"); }

bool ABusStop::getIsTerminal() const { INFO("ABusStop -> method getIsTerminal: called;"); return _isTerminal; }
string ABusStop::getPassengers() const { INFO("ABusStop -> method getPassengers: called;"); return _passengers.show<string>(); }
unsigned short ABusStop::getTotalPassengers() const { INFO("ABusStop -> method getIsTerminal: called;"); return _totalPassengers; }
double ABusStop::getTotalWaitTime() const { INFO("ABusStop -> method getIsTerminal: called;"); return _totalWaitTime; }

void ABusStop::addPassenger(Passenger passenger) { INFO("ABusStop -> method addPassenger: called;"); _passengers.enqueue(passenger); }
void ABusStop::addBus(double currentTime, unsigned short availableSeats)
{
    INFO("ABusStop -> method addBus: called;");

    while (!_passengers.isEmpty() && availableSeats > 0)
    {
        setTotalWaitTime(getTotalWaitTime() + (currentTime - _passengers.front().getArrivalTime()));
        _passengers.dequeue();
        setTotalPassengers(getTotalPassengers() + 1);
        availableSeats--;
    }
}