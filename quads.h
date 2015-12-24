#ifndef QUADS_H
#define QUADS_H

#include "link.h"


class Quads : public Link
{
public:

    Quads(AbstractObject *o)
    {
        linked = o;
    }
    Quads(){}
    virtual  ~Quads(){}
    virtual void getMethod();
};

#endif // QUADS_H
