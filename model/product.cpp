#include "product.h"

int Product::serialnumber = 0;

Product::Product(const QString& Name, const QString& Developer, const QDate& Pubb_date) :
name(Name), developer(Developer), pubb_date(Pubb_date){

  serialnumber++;
  currentSerialNumber=serialnumber;

}

 int Product::getSerialNumber() const {
    return currentSerialNumber;
}

QString Product::getName() const {
    return name;
}
void Product::setName(const QString &n) {
    name=n;
}
QString Product::getDeveloper() const {
    return developer;
}
void Product::setDeveloper(const QString& dev) {
    developer=dev;
}
QDate Product::getDate() const {
    return pubb_date;
}
void Product::setDate(const QDate& d) {
    pubb_date=d;
}


void Product::saveCommonFieldsProduct(QXmlStreamWriter& xmlWriter){
    xmlWriter.writeTextElement("Nome", getName());
    xmlWriter.writeTextElement("Sviluppatore", getDeveloper());
    xmlWriter.writeTextElement("DataPubblicazione", getDate().toString("yyyy.MM.dd"));
}


void Product::loadCommonFieldsProduct(QXmlStreamReader& xmlReader){
    xmlReader.readNextStartElement();
    if(xmlReader.name() == "Nome"){
       setName(xmlReader.readElementText());
       xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "Sviluppatore"){
       setDeveloper(xmlReader.readElementText());
       xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "DataPubblicazione"){
      setDate(QDate::fromString(xmlReader.readElementText(),"yyyy.MM.dd"));
      xmlReader.readNextStartElement();
  }
}


