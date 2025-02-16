#include "printerAbstraction.h"

AStat::AStat(const string& userName, const string& time)
	: _userName(userName), _time(time)
{ CREATE_INFO("AStat <- Constructor: called;"); }
AStat::~AStat() { CREATE_INFO("AStat <- Destructor: called;"); }
string AStat::getUserName() const { INFO("AStat -> AStat getUserName: called;"); return _userName; }
string AStat::getTime() const { INFO("AStat -> AStat getUserName: called;"); return _time; }

template<typename TValue0, typename TValue1> QueueProvider<TValue0>& APrinter<TValue0, TValue1>::getJobQueue() { INFO("APrinter -> method getJobQueue: called;"); return _jobQueue; }
template<typename TValue0, typename TValue1> QueueProvider<TValue1>& APrinter<TValue0, TValue1>::getStatQueue() { INFO("APrinter -> method getStatQueue: called;"); return _statQueue; }
template<typename TValue0, typename TValue1> TValue1 APrinter<TValue0, TValue1>::createStatQueue(const string& userName, const string& time) { INFO("APrinter -> method createStatQueue: called;"); return TValue1(userName, time); }

template<typename TValue0, typename TValue1> size_t APrinter<TValue0, TValue1>::getCounter() const { INFO("APrinter -> method getJobCounter: called;"); return _counter; }
template<typename TValue0, typename TValue1> void APrinter<TValue0, TValue1>::setCounter(const size_t& value) { INFO("APrinter -> method setJobCounter: called;"); _counter = value; }

template<typename TValue0, typename TValue1>
APrinter<TValue0, TValue1>::APrinter()
	: _counter(0)
{ CREATE_INFO("APrinter <- Default constructor: called;"); }
template<typename TValue0, typename TValue1> APrinter<TValue0, TValue1>::~APrinter() { CREATE_INFO("APrinter <- Destructor: called;"); }