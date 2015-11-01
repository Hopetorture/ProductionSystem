#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
class Property
{
public:
    Property(QString s)
    {
        data = s;
    }
    ~Property();
    QString data;
    // сделать указатель на др. property
};

#endif // PROPERTY_H
