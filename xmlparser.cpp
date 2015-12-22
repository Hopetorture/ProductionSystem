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

    QFile xmlFile(this->xmlPath);
    xmlFile.open(QIODevice::ReadOnly | QFile::Text);

    QXmlStreamReader XMLparser;
    XMLparser.setDevice(&xmlFile);

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
                 if (flag)
                 {
                     ObjectPool::instance().pushObj(objID,objLinks,props,objLinksTypes);
                     i++;


                     objLinks.clear();
                     objLinksTypes.clear();
                     objID.clear();
                     props.clear();


                 }
                 flag = true;
                 objID = XMLparser.attributes().value("ID").toString(); //QString
                 objLinks = XMLparser.attributes().value("LinksToID").toString().split(","); //QStringList
                 objLinksTypes = XMLparser.attributes().value("LinksType").toString().split(",");


             }

             if (XMLparser.name() == "property")
             {
                QString qs = XMLparser.attributes().value("text").toString();  //QStr
                props.append(qs);
             }



         }
         else if(XMLparser.isEndElement())
         {
             XMLparser.readNext();
         }
    }

    xmlFile.close();



    ObjectPool::instance().pushObj(objID,objLinks,props,objLinksTypes);
    i++;
    objLinks.clear();
    objID.clear();
    props.clear();

}

