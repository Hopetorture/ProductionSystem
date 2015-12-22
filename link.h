#ifndef LINK_H
#define LINK_H

#include <QObject>
#include "property.h"
class AbstractObject;


class Link
{

public:

   explicit Link();
   virtual ~Link();
   virtual QList<Property*> getMethod()const = 0;
   AbstractObject* getLinked(){return linked;}
   void setLink(AbstractObject *linked)
   {
       this->linked = linked;
   }
   void setParent(AbstractObject* o){parent = o;}

   QString getParentId();
   QString getLinkedId();



protected:
     AbstractObject* linked;
     AbstractObject* parent;
};

#endif // LINK_H
