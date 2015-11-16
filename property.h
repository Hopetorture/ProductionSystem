#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QStringList>
#include <QDebug>
//#include <QList>

class Property
{
public:
    Property(QString s)
    {
        data = s;
    }
    ~Property()
    {
        qDebug() << "Property Destroyed";
    }
    QString data;
   // QList <Property*> ptr;
    QStringList ptrString;
    // сделать указатель на др. property
};

#endif // PROPERTY_H
