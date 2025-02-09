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
	double _departureTime;

	void setDepartureTime(const double& value) override;
public:
	APassenger() = delete;
	APassenger(const double& arrivalTime);
	virtual ~APassenger();

	double getArrivalTime() const override;
	void setArrivalTime(const double& value) override;

	double getDepartureTime() const override;
};

#endif