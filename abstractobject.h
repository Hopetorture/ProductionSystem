#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H


#include <QList>
#include "property.h"
#include <QStringList>
#include <QObject>
#include <QDebug>
#include "link.h"


class IsA;

class AbstractObject //: public QObject
{
  //  Q_OBJECT
public:
    explicit AbstractObject();
    //QObject *parent = 0
    ~AbstractObject();

    //создать фабрику по производству связей

    void addProp(QString s)
    {

        properties.push_back(new Property(s));
      //  qDebug() << properties.last()->data <<"SECOND PHASE";
       // qDebug() << properties.length() <<"SECOND PHASE lenght";
        for ( int i = 0; i < properties.length(); i++)
        {
            //qDebug() << properties[i]->data;
        }
    }
    void setID(QString s){this->id = s;}

    void printProp()const
    {
        for (Property* p : properties)
        {
            qDebug() << p->data;
           // qDebug() <<"baM!";
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

  void coutProperties();
//  {
//      printProp();
//      for (int i = 0; i < isaLinks.length(); i++)
//      {
//        isaLinks[i]->getMethod();
//      }
//  }

  void addLink(AbstractObject *obj, QString type="IsA");
  void addStrLink(QStringList s){stringLinks = s;}
  void init();
//  void test()
//  {
//      for ( int i = 0; i < properties.length(); i++)
//      {
//          qDebug() << properties[i]->data << "LOOK AT MEEE!!1";
//      }
//  }
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
  // qDebug() << this->LinksType;

  }
  QStringList linktype()
  {
     return this->LinksType; //чет тут какая-то муть, нужно разбираться
  }

  //QString ID(){return id;}

  QString id;
  bool visited = false;

 // QList<Property*> getProps(){return this->properties;}
  void addLinksType(QStringList s){LinksType = s;}

private:

    QList <Property*> properties;
    //QList <IsA*> isaLinks;
    QList <Link*> isaLinks;  // стоит ли написать конструктор копирования для Links?
    QStringList stringLinks ; // для корректной инициализации
    QStringList LinksType;


};

#endif // ABSTRACTOBJECT_H
