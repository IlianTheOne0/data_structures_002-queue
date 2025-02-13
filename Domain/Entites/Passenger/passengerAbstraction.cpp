	#include "passengerAbstraction.h"

	APassenger::APassenger() { CREATE_INFO("APassenger <- Default constructor: called;"); setArrivalTime(0.0); }
	APassenger::APassenger(const double& arrivalTime) { CREATE_INFO("APassenger <- Constructor: called;"); setArrivalTime(arrivalTime); }
	APassenger::~APassenger() { CREATE_INFO("APassenger <- Destructor: called;"); }

	double APassenger::getArrivalTime() const { INFO("APassenger -> Method getArrivalTime: called;"); return _arrivalTime; }
	void APassenger::setArrivalTime(const double& value) { INFO("APassenger -> Method setArrivalTime: called;"); _arrivalTime = value; }