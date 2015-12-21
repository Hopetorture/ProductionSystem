#ifndef QUADS_H
#define QUADS_H

#include "link.h"


class Quads : public Link
{
public:
    //Quads();
    Quads(AbstractObject *o) //AbstractObject* o
    {
        linked = o; // link to o
    }
   virtual  ~Quads(){}
   virtual QList<Property*> getMethod()const;
};

#endif // QUADS_H
