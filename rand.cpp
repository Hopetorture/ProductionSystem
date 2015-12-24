#include "rand.h"
#include "abstractobject.h"


#include <QTime>
#include <stdlib.h>
#include <unistd.h>




void Rand::getMethod()
{   
      usleep(1000); //700000 //100000  // change here if on Windows OS, usleep us Unix-only
    QTime seedTime = QTime::currentTime();
    QString seed(seedTime.toString("mmsszzz"));
    unsigned int intSeed = seed.toInt();

     qsrand(intSeed);

   QString Days;
   Days += "Date:";
   Days += QString::number(qrand() % ((this->highDay + 1) - this->lowDay) + this->lowDay);
   QString Months = QString::number(qrand() % ((this->highMonth + 1) - this->lowMonth) + this->lowMonth);

   Days += ".";
   Days += Months;

   qDebug() << Days;
   qDebug() << "Called From:" << parent->getID() << "to:" << linked->getID();

   parent->clear();
   parent->addProp(Days);
   linked->visited = false;

}
