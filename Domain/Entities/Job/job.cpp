#include "job.h"

Job::Job()
	: AJob()
{ CREATE_INFO("Job <- Default constructor: called;"); }
Job::Job(const size_t& id, const string& userName, const string& time)
	: AJob(id, userName, time)
{ CREATE_INFO("Job <- Constructor: called;"); }
Job::~Job() { CREATE_INFO("Job <- Destructor: called;"); }