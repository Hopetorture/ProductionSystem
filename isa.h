#ifndef ISA_H
#define ISA_H

#include "link.h"

#include "abstractobject.h" // solve this shit  объявить их в одном файле?
class IsA : public Link
{
public:
    IsA() //AbstractObject* o
    {
       // linked = o; // link to o.
    }
   virtual  ~IsA();
   virtual QList<Property*> getMethod()
    {
     //   linked->coutProperties();   // как вариант, т.к. не может нормально тут вызвать - написать класс -обработчик
      //   return linked->getPorperties();
        return QList<Property*>();
    }
private:
     AbstractObject* linked;

};

#endif // ISA_H
