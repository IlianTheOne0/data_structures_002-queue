#ifndef PRINTER_ABSTRACTION_H
#define PRINTER_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "../../../Data/data.h"
#include "../Job/job.h"
#include "printerInterface.h"
#include "../Stat/stat.h"

template<typename TValue0, typename TValue1>
class APrinter abstract
    : public IPrinter<TValue0, TValue1>
{
private:
    QueueProvider<TValue0> _jobQueue;
    QueueProvider<TValue1> _statQueue;
    size_t _counter;
protected:
    QueueProvider<TValue0>& getJobQueue() override;
    QueueProvider<TValue1>& getStatQueue() override;
    TValue1 createStatQueue(const size_t& id, const string& userName, const string& time, const string& exectuedTime) override;

    size_t getCounter() const override;
    void setCounter(const size_t& value) override;
public:
    APrinter();
    virtual ~APrinter();
};

#endif