#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QStringList>
#include <QDebug>


class Property
{
public:
    Property(QString s)
    {
        data = s;
    }
    ~Property()
    {

    }
    QString data;   
    QStringList ptrString;

};

#endif // PROPERTY_H
