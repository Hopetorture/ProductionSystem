#ifndef LINK_H
#define LINK_H

#include <QObject>
#include "property.h"
//#include "abstractobject.h"
#include <QSharedPointer>
class AbstractObject;


class Link //: public QObject
{
  //  Q_OBJECT

   //QSharedPointer<AbstractObject> referencedObject;
public:

//  void setPointer(AbstractObject *a)
//  {
//      referencedObject = new QSharedPointer(a);

//  }
   explicit Link();//QObject *parent = 0
   virtual ~Link();
   virtual QList<Property*> getMethod()const = 0;
   AbstractObject* getLinked(){return linked;}


signals:

public slots:
protected:
     AbstractObject* linked;
};

#endif // LINK_H
