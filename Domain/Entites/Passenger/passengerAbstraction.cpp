#include "passengerAbstraction.h"

APassenger::APassenger() { CREATE_INFO("APassenger <- Default constructor: called;"); setArrivalTime(0.0); setDepartureTime(0.0); }
APassenger::APassenger(const double& arrivalTime) { CREATE_INFO("APassenger <- Constructor: called;"); setArrivalTime(arrivalTime); setDepartureTime(0.0); }
APassenger::~APassenger() { CREATE_INFO("APassenger <- Destructor: called;"); }

double APassenger::getArrivalTime() const { INFO("APassenger -> Method getArrivalTime: called;"); return _arrivaleTime; }
void APassenger::setArrivalTime(const double& value) { INFO("APassenger -> Method setArrivalTime: called;"); _arrivaleTime = value; }

double APassenger::getDepartureTime() const { INFO("APassenger -> Method getDepartureTime: called;"); return _departureTime; }
void APassenger::setDepartureTime(const double& value) { INFO("APassenger -> Method setDepartureTime: called;"); _departureTime = value; }