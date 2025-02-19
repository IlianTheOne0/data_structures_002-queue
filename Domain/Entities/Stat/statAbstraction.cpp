#include "statAbstraction.h"

AStat::AStat(const size_t& id, const string& userName, const string& time, const string& executedTime)
	: _id(id), _userName(userName), _time(time), _executedTime(executedTime)
{ CREATE_INFO("AStat <- Constructor: called;"); }
AStat::~AStat() { CREATE_INFO("AStat <- Destructor: called;"); }

size_t AStat::getId() const { INFO("AStat -> AStat getId: called;"); return _id; }

string AStat::getUserName() const { INFO("AStat -> AStat getUserName: called;"); return _userName; }
string AStat::getTime() const { INFO("AStat -> AStat getTime: called;"); return _time; }

string AStat::getExecutedTime() const { INFO("AStat -> AStat getExecutedTime: called;"); return _executedTime; }
void AStat::setExecutedTime(const string& value) { INFO("AStat -> AStat setExecutedTime: called;"); _executedTime = value; }