#include "eventHandler.h"

EventHandler::EventHandler
(
	ABusStop** busStops,
	unsigned short numOfBusStops,
	unsigned short maxPassengersAtStops,
	size_t dayCounter,
	double passengerMorningMin, double passengerMorningMax, double busMorningMin, double busMorningMax,
	double passengerEveningMin, double passengerEveningMax, double busEveningMin, double busEveningMax,
	double passengerAfternoonMin, double passengerAfternoonMax, double busAfternoonMin, double busAfternoonMax
)
	: AEventHandler(busStops, numOfBusStops, maxPassengersAtStops, dayCounter,
		passengerMorningMin, passengerMorningMax, busMorningMin, busMorningMax,
		passengerEveningMin, passengerEveningMax, busEveningMin, busEveningMax,
		passengerAfternoonMin, passengerAfternoonMax, busAfternoonMin, busAfternoonMax)
{ CREATE_INFO("EventHandler <- Constructor: called;"); }

EventHandler::~EventHandler() 
{ CREATE_INFO("EventHandler <- Destructor: called;"); }