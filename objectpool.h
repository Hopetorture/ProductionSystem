#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "abstractobject.h"

/*
 * пул всех "абстрактных" объектов, синглтон майерса
*/

class ObjectPool
{
public:
   ~ObjectPool(){}

    static ObjectPool &instance()
    {
        static ObjectPool config;
        return config;
    }

   void pushObj(QString objID, QStringList objLinks, QStringList props, QStringList type);
   void pushObj(AbstractObject* obj);
   AbstractObject* getPtr(QString s);

   void init();

   void clean();

   QList<AbstractObject*> pool;
private:

    ObjectPool() {}
    ObjectPool(const ObjectPool&) {}
    ObjectPool &operator=(const ObjectPool&) {return *this;}



};

#endif // OBJECTPOOL_H
