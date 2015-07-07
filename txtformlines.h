#ifndef TXTFORMLINES_H
#define TXTFORMLINES_H
#include <txtprocess.h>

class TxtFormLines : public TxtProcess
{
public:
    TxtFormLines();
    virtual QString process(QString input);
};

#endif // TXTFORMLINES_H
