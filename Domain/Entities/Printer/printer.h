#ifndef PRINTER_H
#define PRINTER_H

#include "printerAbstraction.h"

class Stat
	: public AStat
{
public:
	Stat() = delete;
	Stat(const string& userName, const string time);
	~Stat() override;
};

class Printer
	: public APrinter<Job, Stat>
{
public:
	Printer();
	~Printer() override; 
};

#endif