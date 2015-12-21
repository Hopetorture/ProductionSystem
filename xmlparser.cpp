#include "xmlparser.h"


XMLParser::XMLParser()
{

}

void XMLParser::setPath(QString s)
{
    this->xmlPath = s;
}

void XMLParser::Parse()
{
   if (xmlPath.isEmpty())
   {
       qWarning() << "XML path is not defined";
       return;
   }
  //  QList<UI_info_POD> result;
    QFile xmlFile(this->xmlPath);
    xmlFile.open(QIODevice::ReadOnly | QFile::Text);

    QXmlStreamReader XMLparser;
    XMLparser.setDevice(&xmlFile);

   // qDebug() << "start cycle";
  //  UI_info_POD tmp;
  //  bool objPackerActive = false; // флаг целостности объекта
    //QPair <> obj;
    QStringList objLinks;
    QStringList objLinksTypes;
    QString objID;
    QStringList props;    
    bool flag = false;
    int i = 0;

    while (!XMLparser.isEndDocument())
    {
        XMLparser.readNext();
        if (XMLparser.isStartElement())
         {

             if (XMLparser.name() == "object")
             {
                // ObjectPool::instance().pushObj(,);
                 // !!!!!!!!!!!!!!!!!!!!!! костыль-секция
                // if ( podFlag == true)
                // {
                 //result.push_back(UI_info_POD(tmp));  // возможно нужно перенести в др. место.
                 //tmp.clean();
                 //}
               //  objPacker;  // костыль не работает
                 //UI_info_POD question;

                 /*
                  * Баг тут , некорректно инициализируется из XML, индекс ссылок сдвинут на 1.
                  * */


              //   qDebug() << objLinksTypes << " OBJECT LINK TYPES";
                 if (flag) {
                 ObjectPool::instance().pushObj(objID,objLinks,props,objLinksTypes);
                 i++;
//                 qDebug() << i << "ITERATION" ;
//                 qDebug() << objID << "OBJ ID" ;
//                 qDebug() << props << "PROPERTIES" ;
//                 qDebug() << objLinks << "OBJ LINKS" ;

                 objLinks.clear();
                 objLinksTypes.clear();
                 objID.clear();
               //  qDebug() << props;
                 props.clear();


                 }
                 flag = true;
                 objID = XMLparser.attributes().value("ID").toString(); //QString
                 objLinks = XMLparser.attributes().value("LinksToID").toString().split(","); //QStringList
                 objLinksTypes = XMLparser.attributes().value("LinksType").toString().split(",");
                //tmp.questionText = XMLparser.attributes().value("text").toString();
              //  tmp.questionType = XMLparser.attributes().value("type").toInt();
//                qDebug() <<tmp.questionText;
//                qDebug() <<tmp.questionType;

             }
             if (XMLparser.name() == "property")
             {

                // props.push_back(XMLparser.attributes().value("text").toString());  //QStr
                QString qs = XMLparser.attributes().value("text").toString();  //QStr
                //qDebug() << qs;
                props.append(qs);
             //   qDebug() << props;
               //  qDebug() << XMLparser.attributes().value("LinkTo").toString() + "not implenented yet"; //QStrList
//                 tmp.imgX = XMLparser.attributes().value("relPositionX").toInt();
//                 tmp.imgY = XMLparser.attributes().value("relPositionY").toInt();
//                 tmp.image = XMLparser.readElementText();



               // qDebug() << tmp.imagePosition.second;
               // qDebug() << tmp.imagePosition.first << "!231231!!!!!123123";
             }
//             if (XMLparser.name() == "variant")
//             {
//               // tmp.correctVariants.push_back(XMLparser.attributes().value("isCorrect").toInt());
//              //  tmp.variants.push_back(XMLparser.readElementText());
//               // qDebug() << tmp.correctVariants.at(tmp.correctVariants.length()-1) << "abc" ;
//                //qDebug() <<tmp.variants;
//               // qDebug() <<tmp.correctVariants;
//             }


         }
         else if(XMLparser.isEndElement())
         {
             XMLparser.readNext();
         }
    }
  //  result.push_back(tmp); // костыль начал работать
   // qDebug() << result.length();
  // qDebug() << result.at(1).questionText;
    //int n=0;
  //  qDebug() << result.length() << "LENGHT OF THE LIST";
  // for (UI_info_POD obj : result)
  // {
      // qDebug() << n <<"OBJECT:";
     //  n++;
      // obj.state();
  // }

    xmlFile.close();



    ObjectPool::instance().pushObj(objID,objLinks,props,objLinksTypes);
    i++;
    objLinks.clear();
    objID.clear();
    props.clear();

}

