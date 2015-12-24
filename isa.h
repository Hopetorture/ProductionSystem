#ifndef ISA_H
#define ISA_H

#include "link.h"
#include "abstractobject.h"

class IsA : public Link
{
public:
    IsA(AbstractObject *o)
    {
        linked = o;
    }
    IsA(){}
   virtual  ~IsA(){}
   virtual void getMethod();
};

#endif // ISA_H
