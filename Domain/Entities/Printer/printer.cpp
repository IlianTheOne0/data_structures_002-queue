#include "printer.h"

Stat::Stat(const string& userName, const string time)
	: AStat(userName, time)
{ CREATE_INFO("Stat <- Constructor: called;"); }
Stat::~Stat() { CREATE_INFO("Stat <- Destructor: called;"); }

Printer::Printer()
	: APrinter()
{ CREATE_INFO("Printer <- Default constructor: called;"); }
Printer::~Printer() { CREATE_INFO("Printer <- Destructor: called;"); }