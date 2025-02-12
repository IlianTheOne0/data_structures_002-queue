#ifndef EVENTHANDLER_ABSTRACTION_H
#define EVENTHANDLER_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "eventHandlerInterface.h"
#include "../RandomGenerator/randomGenerator.h"

class AEventHandler
	: public IEventHandler
{
private:
	ABusStop** _busStops;
	unsigned short _numOfBusStops;
	unsigned short _maxPassengersAtStops;

	size_t _dayCounter;

	double _passengerMorningMin, _passengerMorningMax, _busMorningMin, _busMorningMax;
	double _passengerAfternoonMin, _passengerAfternoonMax, _busAfternoonMin, _busAfternoonMax;
	double _passengerEveningMin, _passengerEveningMax, _busEveningMin, _busEveningMax;

	double _totalWaitTime;
	size_t _totalTransportedPassengers;
protected:
	void setBusStops(ABusStop** value) override;
	void setNumOfBusStops(const unsigned short& value) override;
	void setMaxPassengersAtStops(const unsigned short& value) override;
	void setDayCounter(const size_t& value) override;
	void setPassengerMorningMin(const double& value) override;
	void setPassengerMorningMax(const double& value) override;
	void setBusMorningMin(const double& value) override;
	void setBusMorningMax(const double& value) override;
	void setPassengerAfternoonMin(const double& value) override;
	void setPassengerAfternoonMax(const double& value) override;
	void setBusAfternoonMin(const double& value) override;
	void setBusAfternoonMax(const double& value) override;
	void setPassengerEveningMin(const double& value) override;
	void setPassengerEveningMax(const double& value) override;
	void setBusEveningMin(const double& value) override;
	void setBusEveningMax(const double& value) override;
	void setTotalWaitTime(const double& value) override;
	void setTotalTransportedPassengers(const size_t& value) override;

	BusStop* getBusStop(const unsigned short& i) const override;

	void getStats() const override;
public:
	AEventHandler() = delete;
	AEventHandler
	(
		ABusStop** busStops,
		unsigned short numOfBusStops,
		unsigned short maxPassengersAtStops,
		size_t dayCounter,
		double passengerMorningMin, double passengerMorningMax, double busMorningMin, double busMorningMax,
		double passengerEveningMin, double passengerEveningMax, double busEveningMin, double busEveningMax,
		double passengeAfternoonMin, double passengerAfternoonMax, double busAfternoonMin, double busAfternoonMax
	);
	virtual ~AEventHandler();

	unsigned short getNumOfBusStops() const override;
	unsigned short getMaxPassengersAtStops() const override;
	size_t getDayCounter() const override;
	double getPassengerMorningMin() const override;
	double getPassengerMorningMax() const override;
	double getBusMorningMin() const override;
	double getBusMorningMax() const override;
	double getPassengerAfternoonMin() const override;
	double getPassengerAfternoonMax() const override;
	double getBusAfternoonMin() const override;
	double getBusAfternoonMax() const override;
	double getPassengerEveningMin() const override;
	double getPassengerEveningMax() const override;
	double getBusEveningMin() const override;
	double getBusEveningMax() const override;
	double getTotalWaitTime() const override;
	size_t getTotalTransportedPassengers() const override;

	void startLoop() override;
};

#endif