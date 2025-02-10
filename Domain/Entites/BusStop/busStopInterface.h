#ifndef BUSSTOP_INTERFACE_H
#define BUSSTOP_INTERFACE_H

class IBusStop
{
private:
	virtual void setIsTerminal(const bool& value) = 0;
	virtual void setTotalPassengers(const unsigned short& value) = 0;
	virtual void setTotalWaitTime(const double& value) = 0;
public:
	virtual bool getIsTerminal() const = 0;
	virtual string getPassengers() const = 0;
	virtual unsigned short getTotalPassengers() const = 0;
	virtual double getTotalWaitTime() const = 0;
	
	virtual void addPassenger(Passenger p) = 0;
	virtual void addBus(double currentTime, unsigned short availableSeats) = 0;
};

#endif