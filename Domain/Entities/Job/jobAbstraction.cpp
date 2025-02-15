#include "jobAbstraction.h"

AJob::AJob()
	: _id(EMPTY_DEFAULT_ID), _userName(EMPTY_DEFAULT_STRING)
{ CREATE_INFO("AJob <- Default constructor: called;"); }
AJob::AJob(const size_t& id, const string& userName)
	: _id(id), _userName(userName)
{ CREATE_INFO("AJob <- Constructor: called;"); }
AJob::~AJob() { CREATE_INFO("AJob <- Destructor: called;"); }

size_t AJob::getId() const { { INFO("AJob -> method getId: called;"); return _id; } }
string AJob::getUserName() const { { INFO("AJob -> method getUserName: called;"); return _userName; } }

void AJob::setId(const size_t& value) { INFO("AJob -> method setId: called;"); _id = value; }
void AJob::setUserName(const string& value) { INFO("AJob -> method setUserName: called;"); _userName = value; }