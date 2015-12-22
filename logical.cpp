#include "logical.h"
#include "propertypool.h"
#include "abstractobject.h"
Logical::Logical()
{

}

QList<Property *> Logical::getMethod() const
{
   QString computationResult = DataPool::instance().strList.join(" = ") + " +";
   computationResult += DataPool::instance().fourTriangles;
   qDebug() << "BigSquare Area = " << computationResult;

   QString subStr = computationResult.split("+").filter("A*B",Qt::CaseInsensitive).join("");
  QString numbers = subStr.split("(").filter("/").join("");
  double frst = numbers.at(1).digitValue();
  frst = frst / numbers.at(3).digitValue();
  frst =  subStr.split(")").filter(" *").join("").remove(" *").at(0).digitValue() * frst;
   //qDebug() << frst << "HELLO";
  QString res = " ";
          res += QString::number(frst);
          res += " A B";
  computationResult.replace(subStr,res);
     qDebug() << "BigSquare Area = " << computationResult;
     subStr =  computationResult.split(" = ").at(1);
   QString a = subStr.at(subStr.indexOf("A"));
   a += "^2";
   QString b = subStr.at(subStr.indexOf("B"));
   b += "^2";
     QString res2 = subStr + " = " + a + " + " + b;
     qDebug() << res2;
     qDebug() << "BigSquare Area = " << QString(s).append("^2 = ").append( res2.split("=").filter(" A^").join("") );


  return QList<Property*>();
}

