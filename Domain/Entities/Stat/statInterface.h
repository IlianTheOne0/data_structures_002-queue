#ifndef PRINTER_STAT_INTERFACE_H
#define PRINTER_STAT_INTERFACE_H

template<typename TReturn>
class IStat
{
public:
	virtual TReturn getUserName() const = 0;
	virtual TReturn getTime() const = 0;

	virtual string getExecutedTime() const = 0;
	virtual void setExecutedTime(const string& value) = 0;
};

#endif