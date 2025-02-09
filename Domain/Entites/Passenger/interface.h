#ifndef PASSENGER_INTERFACE_H
#define PASSENGER_INTERFACE_H

class IPassenger
{
public:
	virtual double getArrivalTime() const = 0;
	virtual void setArrivalTime(const double& value) = 0;
	
	virtual double getDepartureTime() const = 0;
	virtual void setDepartureTime(const double& value) = 0;
};

#endif