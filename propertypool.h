#ifndef PROPERTYPOOL_H
#define PROPERTYPOOL_H

#include "link.h"



class PropertyPool
{
    ~PropertyPool(){}

     static PropertyPool &instance()
     {
         static PropertyPool config;
         return config;
     }
 private:

     QList<Link*> pool;
     PropertyPool() {init();}
     PropertyPool(const PropertyPool&) {}
     PropertyPool &operator=(const PropertyPool&) {return *this;}

     void init() {}
};

#endif // PROPERTYPOOL_H
