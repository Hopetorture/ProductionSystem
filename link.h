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
   virtual void getMethod() = 0;

   AbstractObject* getLinked(){return linked;}
   void setLink(AbstractObject *linked){ this->linked = linked; }
   void setParent(AbstractObject* o){parent = o;}

   void setLinkType(QString s){linkType = s;}
   QString getLinkType(){return this->linkType;}

   QString getParentId();
   QString getLinkedId();



protected:
     AbstractObject* linked;
     AbstractObject* parent;
     QString linkType;
};

#endif // LINK_H
