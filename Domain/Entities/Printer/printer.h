#ifndef PRINTER_H
#define PRINTER_H

#include "printerAbstraction.h"

class Printer
	: public APrinter<Job, Stat>
{
public:
	Printer();
	~Printer() override; 
};

#endif