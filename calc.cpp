#include "calc.h"
#include "abstractobject.h"
#include "objectpool.h"

    int Calc::tries = 0;
    bool Calc::success = false;
    int Calc::successCount = 0;
    double Calc::percent = 0;
Calc::Calc()
{
}


void Calc::getMethod()
{
    qDebug() << "CALC CALLED";
    QString parentDate = parent->getPorperties().filter("Date:").join("");

    for (AbstractObject* obj : ObjectPool::instance().pool)
    {
        if (obj->getID() != parent->getID())
        {
            QString compare1 = obj->getPorperties().filter("Date:").join("");
            if (compare1 == parentDate)
            {
              Calc::success = true;
              Calc::successCount++;
              double ss = Calc::successCount;
              double s = Calc::tries;
              Calc::percent = ss / s;
              qDebug() << "HIT!" << Calc::percent * 100 << "% ," << Calc::successCount << "out of  " << Calc::tries;
              return;
            }
        }
    }
    Calc::success = false;

}

