#include "passenger.h"

Passenger::Passenger(const double& arrivalTime) : APassenger(arrivalTime) { CREATE_INFO("Passenger <- Constructor: called;"); }
Passenger::~Passenger() { CREATE_INFO("Passenger <-Destructor: called; "); }