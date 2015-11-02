#ifndef ISA_H
#define ISA_H

#include "link.h"

#include "abstractobject.h" // solve this shit  объявить их в одном файле?
class IsA : public Link
{
public:
    IsA(AbstractObject *o) //AbstractObject* o
    {
        linked = o; // link to o
    }
   virtual  ~IsA(){}
   virtual QList<Property*> getMethod()const;
//    {
//     //   linked->coutProperties();   // как вариант, т.к. не может нормально тут вызвать - написать класс -обработчик
//      //   return linked->getPorperties();
//        return QList<Property*>();
//    }
/*private:
     AbstractObject* linked;*/ // перенести в родительский класс, иначе будет slicing **done

};

#endif // ISA_H
