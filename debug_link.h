#ifndef DEBUG_LINK_H
#define DEBUG_LINK_H

#include "link.h"


class debug_link : public Link
{
public:
    debug_link();
    virtual ~debug_link(){}
    virtual void getMethod();
};

#endif // DEBUG_LINK_H
