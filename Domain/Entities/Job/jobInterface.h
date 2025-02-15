#ifndef JOB_INTERFACE_H
#define JOB_INTERFACE_H

template<typename TReturn>
class IJob
{
	virtual size_t getId() const = 0;
	virtual TReturn getUserName() const = 0;

	virtual void setId(const size_t& value) = 0;
	virtual void setUserName(const TReturn& value) = 0;
};

#endif