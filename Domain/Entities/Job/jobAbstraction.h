#ifndef JOB_ABSTRACTION_H
#define JOB_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "jobInterface.h"

class AJob
	: public IJob<string>
{
private:
	size_t _id;
	string _userName;
public:
	AJob();
	AJob(const size_t& id, const string& userName);
	virtual ~AJob();

	size_t getId() const override;
	string getUserName() const override;

	void setId(const size_t& value) override;
	void setUserName(const string& value) override;
};

#endif