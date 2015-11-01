#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H


#include <QList>
#include "property.h"
#include <QStringList>
#include <QObject>
#include <QDebug>
#include "link.h"
#include "isa.h"

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
    }

    void printProp()
    {
        for (Property* p : properties)
        {
            qDebug() << p->data;
           // qDebug() <<"baM!";
        }
    }
    QStringList getPorperties()
    {
       QStringList res;
        for (Property* p : properties)
        {
            res.push_back(p->data);


        }
        return res;
    }

  void coutProperties()
  {
      printProp();
      for (int i = 0; i < isaLinks.length(); i++)
      {
     //   isaLinks[i]->getMethod();
      }
  }

private:

    QList <Property*> properties;
    QList <Link*> isaLinks;


};

#endif // ABSTRACTOBJECT_H
