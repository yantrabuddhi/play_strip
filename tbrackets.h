#ifndef TBRACKETS_H
#define TBRACKETS_H
#include <txtprocess.h>

class tBrackets : public TxtProcess
{
public:
    tBrackets();
    virtual QString process(QString input);
};

#endif // TBRACKETS_H
