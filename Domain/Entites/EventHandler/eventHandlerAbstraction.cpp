#include "eventHandlerAbstraction.h"

void AEventHandler::setBusStops(ABusStop** value)
{
	INFO("AEventHandler -> method setBusStop: called;");
	for (size_t i = 0; i < _numOfBusStops; i++)
	{
		_busStops[i] = value[i];
	}
}

void AEventHandler::setNumOfBusStops(const unsigned short& value) { INFO("AEventHandler -> method setNumOfBusStops: called;"); _numOfBusStops = value; }
void AEventHandler::setMaxPassengersAtStops(const unsigned short& value) { INFO("AEventHandler -> method setMaxPassengersAtStops: called;"); _maxPassengersAtStops = value; }
void AEventHandler::setDayCounter(const size_t& value) { INFO("AEventHandler -> method setDayCounter: called;"); _dayCounter = value; }
void AEventHandler::setPassengerMorningMin(const double& value) { INFO("AEventHandler -> method setPassengerMorningMin: called;"); _passengerMorningMin = value; }
void AEventHandler::setPassengerMorningMax(const double& value) { INFO("AEventHandler -> method setPassengerMorningMax: called;"); _passengerMorningMax = value; }
void AEventHandler::setBusMorningMin(const double& value) { INFO("AEventHandler -> method setBusMorningMin: called;"); _busMorningMin = value; }
void AEventHandler::setBusMorningMax(const double& value) { INFO("AEventHandler -> method setBusMorningMax: called;"); _busMorningMax = value; }
void AEventHandler::setPassengerAfternoonMin(const double& value) { INFO("AEventHandler -> method setPassengerAfternoonMin: called;"); _passengerAfternoonMin = value; }
void AEventHandler::setPassengerAfternoonMax(const double& value) { INFO("AEventHandler -> method setPassengerAfternoonMax: called;"); _passengerAfternoonMax = value; }
void AEventHandler::setBusAfternoonMin(const double& value) { INFO("AEventHandler -> method setBusAfternoonMin: called;"); _busAfternoonMin = value; }
void AEventHandler::setBusAfternoonMax(const double& value) { INFO("AEventHandler -> method setBusAfternoonMax: called;"); _busAfternoonMax = value; }
void AEventHandler::setPassengerEveningMin(const double& value) { INFO("AEventHandler -> method setPassengerEveningMin: called;"); _passengerEveningMin = value; }
void AEventHandler::setPassengerEveningMax(const double& value) { INFO("AEventHandler -> method setPassengerEveningMax: called;"); _passengerEveningMax = value; }
void AEventHandler::setBusEveningMin(const double& value) { INFO("AEventHandler -> method setBusEveningMin: called;"); _busEveningMin = value; }
void AEventHandler::setBusEveningMax(const double& value) { INFO("AEventHandler -> method setBusEveningMax: called;"); _busEveningMax = value; }
void AEventHandler::setTotalWaitTime(const double& value) { INFO("AEventHandler -> method setTotalWaitTime: called;"); _totalWaitTime = value; }
void AEventHandler::setTotalTransportedPassengers(const size_t& value) { INFO("AEventHandler -> method setTotalTransportedPassengers: called;"); _totalTransportedPassengers = value; }

BusStop* AEventHandler::getBusStop(const unsigned short& i) const { INFO("AEventHandler -> method getBusStop: called;"); return static_cast<BusStop*>(_busStops[i]); }

AEventHandler::AEventHandler
(
	ABusStop** busStops,
	unsigned short numOfBusStops,
	unsigned short maxPassengersAtStops,
	size_t dayCounter,
	double passengerMorningMin, double passengerMorningMax, double busMorningMin, double busMorningMax,
	double passengerEveningMin, double passengerEveningMax, double busEveningMin, double busEveningMax,
	double passengeAfternoonMin, double passengerAfternoonMax, double busAfternoonMin, double busAfternoonMax
)
	: _busStops(nullptr), _numOfBusStops(numOfBusStops)
{
	CREATE_INFO("AEventHandler <- Constructor: called;");

	_busStops = new ABusStop * [numOfBusStops];
	setBusStops(busStops);
	setMaxPassengersAtStops(maxPassengersAtStops);
	setDayCounter(dayCounter);
	setPassengerMorningMin(passengerMorningMin);
	setPassengerMorningMax(passengerMorningMax);
	setBusMorningMin(busMorningMin);
	setBusMorningMax(busMorningMax);
	setPassengerAfternoonMin(passengeAfternoonMin);
	setPassengerAfternoonMax(passengerAfternoonMax);
	setBusAfternoonMin(busAfternoonMin);
	setBusAfternoonMax(busAfternoonMax);
	setPassengerEveningMin(passengerEveningMin);
	setPassengerEveningMax(passengerEveningMax);
	setBusEveningMin(busEveningMin);
	setBusEveningMax(busEveningMax);
	setTotalWaitTime(0.0);
	setTotalTransportedPassengers(0);
}
AEventHandler::~AEventHandler() { CREATE_INFO("AEventHandler <- Destructor: called;"); delete[] _busStops; }

unsigned short AEventHandler::getNumOfBusStops() const { INFO("AEventHandler -> method getNumOfBusStops: called;"); return _numOfBusStops; }
unsigned short AEventHandler::getMaxPassengersAtStops() const { INFO("AEventHandler -> method getMaxPassengersAtStops: called;"); return _maxPassengersAtStops; }
size_t AEventHandler::getDayCounter() const { INFO("AEventHandler -> method getDayCounter: called;"); return _dayCounter; }
double AEventHandler::getPassengerMorningMin() const { INFO("AEventHandler -> method getPassengerMorningMin: called;"); return _passengerMorningMin; }
double AEventHandler::getPassengerMorningMax() const { INFO("AEventHandler -> method getPassengerMorningMax: called;"); return _passengerMorningMax; }
double AEventHandler::getBusMorningMin() const { INFO("AEventHandler -> method getBusMorningMin: called;"); return _busMorningMin; }
double AEventHandler::getBusMorningMax() const { INFO("AEventHandler -> method getBusMorningMax: called;"); return _busMorningMax; }
double AEventHandler::getPassengerAfternoonMin() const { INFO("AEventHandler -> method getPassengerAfternoonMin: called;"); return _passengerAfternoonMin; }
double AEventHandler::getPassengerAfternoonMax() const { INFO("AEventHandler -> method getPassengerAfternoonMax: called;"); return _passengerAfternoonMax; }
double AEventHandler::getBusAfternoonMin() const { INFO("AEventHandler -> method getBusAfternoonMin: called;"); return _busAfternoonMin; }
double AEventHandler::getBusAfternoonMax() const { INFO("AEventHandler -> method getBusAfternoonMax: called;"); return _busAfternoonMax; }
double AEventHandler::getPassengerEveningMin() const { INFO("AEventHandler -> method getPassengerEveningMin: called;"); return _passengerEveningMin; }
double AEventHandler::getPassengerEveningMax() const { INFO("AEventHandler -> method getPassengerEveningMax: called;"); return _passengerEveningMax; }
double AEventHandler::getBusEveningMin() const { INFO("AEventHandler -> method getBusEveningMin: called;"); return _busEveningMin; }
double AEventHandler::getBusEveningMax() const { INFO("AEventHandler -> method getBusEveningMax: called;"); return _busEveningMax; }
double AEventHandler::getTotalWaitTime() const { INFO("AEventHandler -> method getTotalWaitTime: called;"); return _totalWaitTime; }
size_t AEventHandler::getTotalTransportedPassengers() const { INFO("AEventHandler -> method getTotalTransportedPassengers: called;"); return _totalTransportedPassengers; }

void AEventHandler::startLoop()
{
    double currentTime{}, passengerInterval{}, busInterval{};
    for (size_t day = 0; day < getDayCounter(); day++)
    {
        currentTime = 5.5;

        while (currentTime <= 23.0)
        {
            if (currentTime >= 5.5 && currentTime < 12)
            {
                passengerInterval = RandomGenerator::generateNumber(getPassengerMorningMin(), getPassengerMorningMax());
                busInterval = RandomGenerator::generateNumber(getBusMorningMin(), getBusMorningMax());
            }
            else if (currentTime >= 12.0 && currentTime < 20.0)
            {
                passengerInterval = RandomGenerator::generateNumber(getPassengerAfternoonMin(), getPassengerAfternoonMax());
                busInterval = RandomGenerator::generateNumber(getBusAfternoonMin(), getBusAfternoonMax());
            }
            else if (currentTime >= 20.0 && currentTime < 23.0)
            {
                passengerInterval = RandomGenerator::generateNumber(getPassengerEveningMin(), getPassengerEveningMax());
                busInterval = RandomGenerator::generateNumber(getBusEveningMin(), getBusEveningMax());
            }
            else
            {
                break;
            }

            double nextPassengerTime = currentTime + RandomGenerator::generateNumber(passengerInterval * 0.8, passengerInterval * 1.2);
            double nextBusTime = currentTime + RandomGenerator::generateNumber(busInterval * 0.8, busInterval * 1.2);

			while (currentTime < nextBusTime && currentTime <= 23.0)
			{
				unsigned short randomIndex = RandomGenerator::generateNumber(long long(0), long long(getNumOfBusStops() - 1));
				_busStops[randomIndex]->addPassenger(Passenger(currentTime));

				currentTime = nextPassengerTime;
				nextPassengerTime = currentTime + RandomGenerator::generateNumber(passengerInterval * 0.8, passengerInterval * 1.2);
			}


            if (currentTime <= 23.0)
            {
                for (unsigned short i = 0; i < getNumOfBusStops(); i++)
                {
                    ABusStop* stop = _busStops[i];

					unsigned short previousTotal = stop->getTotalPassengers();
					double previousWaitingTime = stop->getTotalWaitTime();

                    unsigned short availableSeats = RandomGenerator::generateNumber(long long(getMaxPassengersAtStops() * 0.2), long long(getMaxPassengersAtStops()));
					stop->addBus(currentTime, availableSeats);

					setTotalTransportedPassengers(getTotalTransportedPassengers() + (stop->getTotalPassengers() - previousTotal));
					setTotalWaitTime(getTotalWaitTime() + (stop->getTotalWaitTime() - previousWaitingTime));
                }
            }

            currentTime += busInterval;
        }
    }

    getStats();
}

void AEventHandler::getStats() const
{
	INFO("AEventHandler -> method getStats: called;");

	if (!Logger::getLoggerState()) { system("cls"); }

	double avarageWaitTime = ((getTotalTransportedPassengers() > 0) ? getTotalWaitTime() / getTotalTransportedPassengers() : NULL);

	cout << "Results:" << endl;
	
	bool areStopsSufficient{ true }; unsigned short totalMaxQueue{};
	cout << "  The total number of passengers served at each stop: " << endl;
	for (unsigned short i = 0; i < getNumOfBusStops(); i++)
	{
		cout << "    Bus Stop Num. " << i + 1 << ". Trasported: " << getBusStop(i)->getTotalPassengers() << endl;

		if (getBusStop(i)->getMaxQueueLength() > totalMaxQueue) { totalMaxQueue = getBusStop(i)->getMaxQueueLength(); }
		if (getBusStop(i)->getMaxQueueLength() > getMaxPassengersAtStops()) { areStopsSufficient = false; }
	}
	cout << endl;

	cout << "    Number of iterations: " << getDayCounter() << endl;
	cout << "    Total transported passengers: " << getTotalTransportedPassengers() << endl;
	cout << "    Avarage wait time: " << avarageWaitTime << " time units" << endl;
	cout << "    Total max queue: " << setw(2); ((totalMaxQueue == getMaxPassengersAtStops()) ? cout << '<' << totalMaxQueue : cout << totalMaxQueue); cout << endl;
	cout << endl;

	cout << "Conclusion:" << endl;
	if (areStopsSufficient) { cout << "  Bus arrival intervals are sufficient to ensure that the number of waiting passengers does not exceed " << _maxPassengersAtStops << " people" << endl; }
	else { cout << "  Bus arrival intervals are insufficient. Consider reducing the interval between bus arrivals" << endl; }
}