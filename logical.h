#ifndef LOGICAL_H
#define LOGICAL_H

#include "link.h"

class Logical : public Link
{
public:
    Logical();
    virtual ~Logical(){}
    virtual void getMethod();
private:
    QString s = "C";
};

#endif // LOGICAL_H
