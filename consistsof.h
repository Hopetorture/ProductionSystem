#ifndef CONSISTSOF_H
#define CONSISTSOF_H

#include "link.h"

class ConsistsOf : public Link
{
public:
    ConsistsOf(AbstractObject *o)
    {
        linked = o;
    }
    ConsistsOf(){}
   virtual  ~ConsistsOf(){}
   virtual void getMethod();
};

#endif // CONSISTSOF_H
