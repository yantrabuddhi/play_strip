#ifndef TCAPS_H
#define TCAPS_H
#include <txtprocess.h>


class tCaps : public TxtProcess
{
public:
    tCaps();
    virtual QString process(QString input);
};

#endif // TCAPS_H
