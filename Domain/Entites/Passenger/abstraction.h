#ifndef PASSENGER_ABSTRACTION_H
#define PASSENGER_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "interface.h"

class APassenger
	: public IPassenger
{
private:
	double _arrivaleTime;
public:
	APassenger() = delete;
	APassenger(const double& arrivalTime);
	virtual ~APassenger();

	virtual double getArrivalTime() const;
	virtual void setArrivalTime(const double& value);
};

#endif