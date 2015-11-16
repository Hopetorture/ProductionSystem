#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QString>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>


#include "objectpool.h"
#include "propertypool.h"



class XMLParser
{
public:
     XMLParser(const QString &path);
     XMLParser();
    ~XMLParser(){}
    void setPath(QString s);
    void Parse(const QString &path);
    void Parse(); // придумать, что возвращать. pair (obj, links) pair (properties,links) (mb?)
        // или сразу закидывать все в пулы объектов.
private:
    QString xmlPath;
};

#endif // XMLPARSER_H
