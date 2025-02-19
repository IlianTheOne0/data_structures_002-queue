#include "stat.h"

Stat::Stat()
	: AStat(EMPTY_DEFAULT_ID, EMPTY_DEFAULT_STRING, EMPTY_DEFAULT_STRING, EMPTY_DEFAULT_STRING)
{ CREATE_INFO("Stat <- Default constructor: called;"); }
Stat::Stat(const size_t& id, const string& userName, const string& time, const string& executedTime)
	: AStat(id, userName, time, executedTime)
{ CREATE_INFO("Stat <- Constructor: called;"); }
Stat::~Stat() { CREATE_INFO("Stat <- Destructor: called;"); }