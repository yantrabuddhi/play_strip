#include "tbrackets.h"
#include <QStringList>
#include <QRegularExpression>
#include <QChar>
#include <QDebug>

tBrackets::tBrackets()
{

}

QString tBrackets::process(QString input)
{

    //QRegularExpression rex1("\\[.+\\]");
    QRegularExpression rex1("\\[[^\\[^\\]]+\\]");//first replace \n
    QString o1=input.replace(rex1,"\n");
    return o1;
}
