#ifndef TSPACEDOT_H
#define TSPACEDOT_H
#include <txtprocess.h>

class tSpaceDot : public TxtProcess
{
public:
    tSpaceDot();
    virtual QString process(QString input);
};

#endif // TSPACEDOT_H
