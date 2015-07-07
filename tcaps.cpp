#include "tcaps.h"
#include <QStringList>
#include <QRegularExpression>
#include <QChar>
#include <QDebug>

tCaps::tCaps()
{

}

QString tCaps::process(QString input)
{

    //QRegularExpression rex1("\\[.+\\]");
    QRegularExpression rex1("[A-Z][A-Z]+");//first replace \n
    QString o1=input.replace(rex1,".");
    return o1;
}
