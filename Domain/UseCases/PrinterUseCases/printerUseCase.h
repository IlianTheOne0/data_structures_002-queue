#ifndef PRINTER_USECASE_H
#define PRINTER_USECASE_H

#include "../../Entities/Printer/printer.h"

class PrinterUseCase
	: public Printer
{
private:
	string getCurrentTime() const;
public:
	PrinterUseCase();
	~PrinterUseCase() override;

	void addJob(const string& userName);
	void addJob(const string& userName, Priority priority);
	void addJob(const string& userName, Priority priority, const string& time);
	void processJob();

	void getInfo();
};

#endif