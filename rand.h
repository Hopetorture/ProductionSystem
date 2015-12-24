#ifndef RAND_H
#define RAND_H

#include "link.h"

class Rand : public Link
{
public:
    Rand(){}
    virtual  ~Rand(){}
    virtual void getMethod();
private:
    int lowMonth = 1;
    int highMonth = 12;

    int lowDay = 1;
    int highDay = 30;
};

#endif // RAND_H
