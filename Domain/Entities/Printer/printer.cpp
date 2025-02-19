#include "printer.h"

Printer::Printer()
	: APrinter()
{ CREATE_INFO("Printer <- Default constructor: called;"); }
Printer::~Printer() { CREATE_INFO("Printer <- Destructor: called;"); }