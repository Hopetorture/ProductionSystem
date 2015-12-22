#ifndef PARTOF_H
#define PARTOF_H

#include "link.h"


class PartOf : public Link
{
public:
    PartOf(AbstractObject *o)
    {
        linked = o;
    }
    PartOf(){}
   virtual  ~PartOf(){}
   virtual QList<Property*> getMethod()const;
};

#endif // PARTOF_H
