#ifndef CALC_H
#define CALC_H

#include "link.h"

class Calc : public Link
{
public:
    Calc();
    virtual ~Calc(){}
    virtual void getMethod() ;

    static int tries;
    static bool success;
    static int successCount ;
    static double percent;

private:

};


#endif // CALC_H
