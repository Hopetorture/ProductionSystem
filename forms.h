#ifndef FORMS_H
#define FORMS_H

#include "link.h"


class Forms : public Link
{
public:
    Forms(AbstractObject *o)
    {
        linked = o;
    }
    Forms(){}
   virtual  ~Forms(){}
   virtual QList<Property*> getMethod()const;
};

#endif // FORMS_H
