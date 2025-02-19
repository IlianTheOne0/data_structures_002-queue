#ifndef JOB_H
#define JOB_H

#include "jobAbstraction.h"

class Job
	: public AJob
{
public:
	Job();
	Job(const size_t& id, const string& userName, const string& time);
	~Job() override;
};

#endif