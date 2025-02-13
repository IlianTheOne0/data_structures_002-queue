#ifndef EVENTHANDLER_INTERFACE_H
#define EVENTHANDLER_INTERFACE_H

#include "../BusStop/busStop.h"

class IEventHandler
{
protected:
	virtual void setBusStops(ABusStop** value) = 0;
	virtual void setNumOfBusStops(const unsigned short& value) = 0;
	virtual void setMaxPassengersAtStops(const unsigned short& value) = 0;
	virtual void setDayCounter(const size_t& value) = 0;
	virtual void setPassengerMorningMin(const double& value) = 0;
	virtual void setPassengerMorningMax(const double& value) = 0;
	virtual void setBusMorningMin(const double& value) = 0;
	virtual void setBusMorningMax(const double& value) = 0;
	virtual void setPassengerAfternoonMin(const double& value) = 0;
	virtual void setPassengerAfternoonMax(const double& value) = 0;
	virtual void setBusAfternoonMin(const double& value) = 0;
	virtual void setBusAfternoonMax(const double& value) = 0;
	virtual void setPassengerEveningMin(const double& value) = 0;
	virtual void setPassengerEveningMax(const double& value) = 0;
	virtual void setBusEveningMin(const double& value) = 0;
	virtual void setBusEveningMax(const double& value) = 0;
	virtual void setTotalWaitTime(const double& value) = 0;
	virtual void setTotalTransportedPassengers(const size_t& value) = 0;

	virtual BusStop* getBusStop(const unsigned short& i) const = 0;

	virtual void getStats() const = 0;
public:
	virtual unsigned short getNumOfBusStops() const = 0;
	virtual unsigned short getMaxPassengersAtStops() const = 0;
	virtual size_t getDayCounter() const = 0;
	virtual double getPassengerMorningMin() const = 0;
	virtual double getPassengerMorningMax() const = 0;
	virtual double getBusMorningMin() const = 0;
	virtual double getBusMorningMax() const = 0;
	virtual double getPassengerAfternoonMin() const = 0;
	virtual double getPassengerAfternoonMax() const = 0;
	virtual double getBusAfternoonMin() const = 0;
	virtual double getBusAfternoonMax() const = 0;
	virtual double getPassengerEveningMin() const = 0;
	virtual double getPassengerEveningMax() const = 0;
	virtual double getBusEveningMin() const = 0;
	virtual double getBusEveningMax() const = 0;
	virtual double getTotalWaitTime() const = 0;
	virtual size_t getTotalTransportedPassengers() const = 0;

	virtual void startLoop() = 0;
};

#endif