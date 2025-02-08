#ifndef PASSENGER_H
#define PASSENGER_H

#include "abstraction.h"

class Passenger
	: public APassenger
{
public:
	Passenger() = delete;
	Passenger(const double& arrivalTime);
	~Passenger() override;
};

#endif