#include "tspacedot.h"
#include <QStringList>
#include <QRegularExpression>
#include <QRegExp>
#include <QChar>
#include <QDebug>

tSpaceDot::tSpaceDot()
{

}

QString tSpaceDot::process(QString input)
{

    //QRegularExpression rex1("\\[.+\\]");
    QRegularExpression rex1("\\s\\s+");//first replace \n
    QString o1=input.replace(rex1," ");
    o1=o1.replace(QRegExp("\\s\\.+"),".");
    o1=o1.replace(QRegExp("\\.+\\s"),"\n");
    o1=o1.replace(QRegExp("\\.\\.\\.+"),"\n");
    o1=o1.replace(QRegExp("\\.\\.")," ");
    //o1=o1.replace(QRegExp("\\.\\w")," ");
    return o1;
}
