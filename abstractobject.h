#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H


#include <QList>
#include "property.h"
#include <QStringList>
#include <QObject>
#include <QDebug>
#include "link.h"


class IsA;

class AbstractObject
{
public:
    explicit AbstractObject();
    ~AbstractObject();

    void addProp(QString s)
    {
        properties.push_back(new Property(s));
    }

    void setID(QString s){this->id = s;}

    void printProp()const
    {
        for (Property* p : properties)
        {
            qDebug() << p->data;
        }
    }

    QStringList getPorperties() const
    {
       QStringList res;
        for (Property* p : properties)
        {
            res.push_back(p->data);


        }
        return res;
    }

  void massInvoke(bool doPrintProp);
  void singleInvoke(QString s);


  void addLink(AbstractObject *obj, QString type="IsA");
  void addStrLink(QStringList s){stringLinks = s;}
  void init();

  void dbg()
  {
   qDebug() << "this object ID is:" << id;
   qDebug() << "this properies lenght is:";
   qDebug() <<  this->properties.length(); // lenght - zero.
   qDebug() << "this properies  is:";

   for (Property* a : this->properties)
   {
      qDebug() <<  a->data;
   }
   qDebug() << "-----------------";
   qDebug() << "this object points to:";
   for (Link* a: isaLinks)
   {
       a->getMethod();
   }
   qDebug() << "---------------";
   qDebug() << "YYYYYYYYYYYYYYYYYYY";
   qDebug() << "type:";

  }

  QStringList linktype()
  {
     return this->LinksType;
  }  

  QString id;
  bool visited = false;
  void addLinksType(QStringList s){LinksType = s;}

private:

    QList <Property*> properties;
    QList <Link*> isaLinks;
    QStringList stringLinks ; // для корректной инициализации
    QStringList LinksType;


};

#endif // ABSTRACTOBJECT_H
