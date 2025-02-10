#ifndef PASSENGER_ABSTRACTION_H
#define PASSENGER_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "passengerInterface.h"

class APassenger abstract
	: public IPassenger
{
private:
	double _arrivaleTime;
	double _departureTime;
public:
	APassenger();
	APassenger(const double& arrivalTime);
	virtual ~APassenger();

	double getArrivalTime() const override;
	void setArrivalTime(const double& value) override;

	double getDepartureTime() const override;
	void setDepartureTime(const double& value) override;
};

#endif