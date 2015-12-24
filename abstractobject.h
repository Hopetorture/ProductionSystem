#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QList>
#include <QStringList>
#include <QObject>
#include <QDebug>

#include "property.h"
#include "link.h"


class IsA;

class AbstractObject
{
public:
    explicit AbstractObject(QString s): id(s) {}
    ~AbstractObject();

    void printProp()const;
    QStringList getPorperties() const;

    void massInvoke(bool doPrintProp);
    void singleInvoke(QString s);

    void addLink(AbstractObject *obj, QString type="IsA");
    void init();

    void addStrLink(QStringList s){stringLinks = s;}
    QStringList linktype() { return this->LinksType; }

    void addProp(QString s){ properties.push_back(new Property(s)); }
    void addLinksType(QStringList s){LinksType = s;}

    void clear(){this->properties.clear();}
    QString getID(){return this->id;}


    bool visited = false;

private:

    const QString id;
    QList <Property*> properties;
    QList <Link*> isaLinks;
    QStringList stringLinks ; // для корректной инициализации
    QStringList LinksType;


};

#endif // ABSTRACTOBJECT_H
