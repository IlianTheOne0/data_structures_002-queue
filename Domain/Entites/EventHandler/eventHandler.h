#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "eventHandlerAbstraction.h"

class EventHandler
	: public AEventHandler
{
public:
	EventHandler() = delete;
	EventHandler
	(
		ABusStop** busStops,
		unsigned short numOfBusStops,
		unsigned short maxPassengersAtStops,
		size_t dayCounter,
		double passengerMorningMin, double passengerMorningMax, double busMorningMin, double busMorningMax,
		double passengerEveningMin, double passengerEveningMax, double busEveningMin, double busEveningMax,
		double passengeAfternoonMin, double passengerAfternoonMax, double busAfternoonMin, double busAfternoonMax
	);
	~EventHandler() override;
};

#endif