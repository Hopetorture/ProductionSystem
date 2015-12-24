#ifndef PROPERTYPOOL_H
#define PROPERTYPOOL_H

#include "link.h"


class DataPool
{
    ~DataPool(){}

public:
     static DataPool &instance()
     {
         static DataPool config;
         return config;
     }

      QStringList strList;
      QString fourTriangles;
      QString bigSq;
      void clear(){strList.clear();fourTriangles.clear();bigSq.clear();}
 private:

     DataPool() {init();}
     DataPool(const DataPool&) {}
     DataPool &operator=(const DataPool&) {return *this;}

     void init() {}

};

#endif // PROPERTYPOOL_H
