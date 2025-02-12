#include "busStopAbstraction.h"

void ABusStop::setIsTerminal(const bool& value) {INFO("ABusStop -> method setIsTerminal: called;"); _isTerminal = value; }
void ABusStop::setTotalPassengers(const unsigned short& value) {INFO("ABusStop -> method setTotalPassengers: called;"); _totalPassengers = value; }
void ABusStop::setTotalWaitTime(const double& value) {INFO("ABusStop -> method setTotalWaitTime: called;"); _totalWaitTime = value; }
void ABusStop::setCurrentQueueLength(const unsigned short& value) { INFO("ABusStop -> method setMaxQueueLength: called;"); _currentQueueLength = value; }
void ABusStop::setMaxQueueLength(const unsigned short& value) { INFO("ABusStop -> method setCurrentQueueLength: called;"); _maxQueueLength = value; }

ABusStop::ABusStop(bool isTerminal, unsigned short maxQueueLength)
	: _isTerminal(isTerminal), _maxQueueLength(maxQueueLength)
{ CREATE_INFO("ABusStop <- Constructor: called;"); }
ABusStop::~ABusStop() { CREATE_INFO("ABusStop <- Destructor: called;"); }

bool ABusStop::getIsTerminal() const { INFO("ABusStop -> method getIsTerminal: called;"); return _isTerminal; }
string ABusStop::getPassengers() const { INFO("ABusStop -> method getPassengers: called;"); return _passengers.show<string>(); }
unsigned short ABusStop::getTotalPassengers() const { INFO("ABusStop -> method getIsTerminal: called;"); return _totalPassengers; }
double ABusStop::getTotalWaitTime() const { INFO("ABusStop -> method getIsTerminal: called;"); return _totalWaitTime; }
unsigned short ABusStop::getCurrentQueueLength() const { INFO("ABusStop -> method getMaxQueueLength: called;"); return _currentQueueLength; }
unsigned short ABusStop::getMaxQueueLength() const { INFO("ABusStop -> method getMaxQueueLength: called;"); return _maxQueueLength; }

void ABusStop::addPassenger(Passenger passenger) { INFO("ABusStop -> method addPassenger: called;"); _passengers.enqueue(passenger); if (getCurrentQueueLength() > getMaxQueueLength()) { setMaxQueueLength(getCurrentQueueLength()); } }
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