#ifndef PRINTER_INTERFACE_H
#define PRINTER_INTERFACE_H

template<typename TReturn0, typename TReturn1>
class IPrinter
{
protected:
	virtual QueueProvider<TReturn0>& getJobQueue() = 0;
	virtual QueueProvider<TReturn1>& getStatQueue() = 0;
	virtual TReturn1 createStatQueue(const size_t& id, const string& userName, const string& time, const string& exectuedTime) = 0;

	virtual size_t getCounter() const = 0;
	virtual void setCounter(const size_t& value) = 0;
};

#endif