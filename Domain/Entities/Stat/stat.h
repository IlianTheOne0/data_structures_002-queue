#ifndef PRINTER_STAT_H
#define PRINTER_STAT_H

#include "statAbstraction.h"

class Stat
    : public AStat
{
public:
    Stat();
    Stat(const size_t& id, const string& userName, const string& time, const string& executedTime);
    ~Stat() override;
};

#endif