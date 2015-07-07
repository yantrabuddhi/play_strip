#include "txtformlines.h"
#include <QStringList>
#include <QRegularExpression>
#include <QChar>
#include <QDebug>
TxtFormLines::TxtFormLines()
{

}

QString TxtFormLines::process(QString input)
{

    QRegularExpression rex1("(\r\n){2}+");//first replace \n
    QString o1=input.replace(rex1,"\n");
    QRegularExpression rex2("[\\.\\?]?\\.+");
    QString o2=o1.replace(rex2,".");
    QRegularExpression rex3("(\r\n)");
    o1=o2.replace(rex3," ");
    QRegularExpression rex4("\n\n+");
    o2=o1.replace(rex4,".");
    QRegularExpression rex5("\\.|\\?");
    o1=o2.replace(rex5,"\n");
    /*
    o2=o1.replace(rex4,"\n");
    QRegularExpression rex6("\\s\n");
    o1=o2.replace(rex6,"");
    */
    return o1;
}
