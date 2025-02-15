#include "job.h"

Job::Job()
	: AJob()
{ CREATE_INFO("Job <- Default constructor: called;"); }
Job::Job(const size_t& id, const string& userName)
	: AJob(id, userName)
{ CREATE_INFO("Job <- Constructor: called;"); }
Job::~Job() { CREATE_INFO("Job <- Destructor: called;"); }