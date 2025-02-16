#ifndef PRINTER_USECASE_H
#define PRINTER_USECASE_H

#include "../../Entities/Printer/printer.h"

class PrinterUseCase
	: public Printer
{
public:
	PrinterUseCase();
	~PrinterUseCase() override;

	void addJob(const string& userName);
	void addJob(const string& userName, Priority priority);
	void processJob();

	void getInfo();
};

#endif