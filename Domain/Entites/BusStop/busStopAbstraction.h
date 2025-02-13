#ifndef BUSSTOP_ABSTRACTION_H
#define BUSSTOP_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "../../../Data/data.h"
#include "../Passenger/passenger.h"
#include "busStopInterface.h"

class ABusStop abstract
	: public IBusStop
{
private:
	bool _isTerminal;
	Queue<Passenger> _passengers;
	unsigned short _totalPassengers{};
	double _totalWaitTime{};
	unsigned short _currentQueueLength{};
	unsigned short _maxQueueLength{};

	void setIsTerminal(const bool& value) override;
	void setTotalPassengers(const unsigned short& value) override;
	void setTotalWaitTime(const double& value) override;
	void setCurrentQueueLength(const unsigned short& value) override;
	void setMaxQueueLength(const unsigned short& value) override;
public:
	ABusStop() = delete;
	ABusStop(bool isTreminal, unsigned short maxQueueLength);
	virtual ~ABusStop();

	bool getIsTerminal() const override;
	string getPassengers() const override;
	unsigned short getTotalPassengers() const override;
	double getTotalWaitTime() const override;
	unsigned short getCurrentQueueLength() const override;
	unsigned short getMaxQueueLength() const override;

	void addPassenger(Passenger p) override;
	void addBus(double currentTime, unsigned short availableSeats) override;
};

#endif