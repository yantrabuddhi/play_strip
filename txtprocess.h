#ifndef TXTPROCESS_H
#define TXTPROCESS_H

#include <QString>

class TxtProcess
{
public:
    TxtProcess();
    virtual QString process(QString input)=0;
};

#endif // TXTPROCESS_H
