#ifndef PASSENGER_H
#define PASSENGER_H

#include "passengerAbstraction.h"

class Passenger
	: public APassenger
{
public:
	Passenger();
	Passenger(const double& arrivalTime);
	~Passenger() override;
};

#endif