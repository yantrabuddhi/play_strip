#include "tcaps.h"
#include <QStringList>
#include <QRegularExpression>
#include <QRegExp>
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
    o1=o1.replace(QRegExp("[A-Z][a-z]+(\\.|:)"),".");//try
    o1=o1.replace(QRegExp("\\.[A-Z]+(\\.|:)"),".");
    return o1;
}
