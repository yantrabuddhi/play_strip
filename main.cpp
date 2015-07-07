//#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <txtprocess.h>
#include <txtformlines.h>
#include <tbrackets.h>
#include <tcaps.h>
#include <tspacedot.h>
#include <QMap>
#include <QList>
#include <iostream>
#include <QFile>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QMap<QString,TxtProcess*> map;
    map["rel"]=new TxtFormLines();
    map["brak"]=new tBrackets();
    map["caps"]=new tCaps();
    map["dotspc"]=new tSpaceDot();
    //if argv < 2 display help
    if (argc<3){
        //help;
        std::cout<<"\nUsage: play_strip hello.txt <p1> <p2> .. <pn>\n";
        QList<QString> keys=map.keys();
        foreach(QString s,keys){
            std::cout<<s.toStdString()<<", ";
        }
        std::cout<<"\n";

        return -1;
    }
    for (int i=2;i<argc;i++){
        if (!(map.contains(QString(argv[i])))){
            std::cout<<"\n incorrect command: ["<<i<<"]"<<argv[i]<<"\n";
            return -1;
        }
    }
    //load a file mentioned in argv[1]
    QFile dev(argv[1]);
    dev.open(QIODevice::ReadOnly);
    QTextStream ts(&dev);
    QString input=ts.readAll();
    dev.close();
    //apply sequence of strips by command line argv 2 to n
    QString output;
    for (int i=2;i<argc;i++){
        output=(map[QString(argv[i])])->process(input);
        input=output;
    }
    //write output
    QString ofs=(argv[1]);
    ofs+=".out.txt";
    dev.setFileName(ofs);
    dev.open(QIODevice::WriteOnly);
    QTextStream out(&dev);
    out<<output;
    out.flush();
    dev.close();
    QList<QString> keys=map.keys();
    foreach(QString s,keys){
        delete map[s];
    }

    return 0;
    //return a.exec();
}
//need to offset?
//need to make one line's
//need to remove []
//need to remove names [starting each line ending with . >3 characters]
//need to remove <3 chars with .'s Mr. Ms. X. - don't count spaces
//need to split sentences to new lines [discard extra dots]
//make one lines,remove [] from all lines,remove names from all lines,split lines to sentences
