#include"product_database.h"

QString productDatabase::filename="../ProgettoP2/model/productDatabase.xml";

productDatabase::productDatabase(){ Load(); }

productDatabase::~productDatabase(){
    SaveAndClose();
   auto it=products.begin();
   for(; it!=products.end(); ++it){
       delete *it;
       it=products.erase(it);
        it--;
    }
}

void productDatabase::Load(){
    QFile file(filename);
 //   if(!file.exists()){
  // filename = QFileDialog::getSaveFileName((QWidget* )0,"Crea database Xml in cui salvare i dati", ".","Xml files (*.xml)");
   //   }
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();
        while(!xmlReader.atEnd()){
            Product* t=nullptr;
            if(xmlReader.name()=="Videogame-Base"){ t=new Base;}
            else if(xmlReader.name()=="Videogame-Limited"){t=new Limited;}
            else if(xmlReader.name()=="Console-NewGeneration"){t=new NewGeneration;}
            else if(xmlReader.name()=="Console-RetroConsole"){t=new RetroConsole;}
            if(t){
                t->loadProduct(xmlReader);
                products.push_back(t);
            }

              xmlReader.readNextStartElement();

        }
    }

    else{
        QMessageBox::warning(0,"File mancanti","Creazione file di default");
    }
}


void productDatabase::SaveAndClose(){
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Prodotti");
    auto it=products.begin();
    for( ;it!=products.end();++it){
        (*it)->saveProduct(xmlWriter);

    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();

}
/*
bool productDatabase::isEmpty() const{
    return products.size();
}*/

void productDatabase::addProductToDB(Product* p){
    products.push_back(p);
}

void productDatabase::removeProductFromDB(Product* p){
    auto it=products.begin();
    for( ; it!=products.end(); ++it){
        if((*it)->getSerialNumber() == p->getSerialNumber()){
            delete *it;
            it=products.erase(it);
            it--;
        }
    }
}

Product* productDatabase::getProduct(int serialnumber)const{
   Product* p = nullptr;
    auto it=products.begin(); //scorro tutto il database
    for( ;it!=products.end(); ++it){
           if((*it)->getSerialNumber() == serialnumber){ //se trovo il prodotto che cerco
            p = *it;
             }
        }

    return p;
}

/***********  METODO PER BARRA DI RICERCA  ***********/
const QList<Product*> productDatabase::productContainsWord(const QString & word) const{
    QList<Product*> temp; bool result=false;
    for(auto it=products.begin(); it!=products.end(); ++it){
    if( (*it)->getName().contains(word, Qt::CaseInsensitive) || (*it)->getDeveloper().contains(word, Qt::CaseInsensitive)){
        temp.push_back(*it);
        result=true;
      }
    }
    if(result == false)
       QMessageBox::warning(0,"Attenzione","Nessun risultato, riprova!");

    return temp;
}

const QList<Product*> productDatabase::getAllProducts()const{
    QList<Product*> temp;
    for(auto it=products.begin(); it!=products.end(); ++it){
        temp.push_back(*it);
    }
    return temp;
}





/***********  METODI DI RICERCA PER VIDEOGAME GENERALI  ***********/
QList<Product*> productDatabase::videogameRemake() const{
  QList<Product*> videogames;
  for(auto it = products.begin(); it !=products.end(); ++it){
      Videogame* v = dynamic_cast<Videogame*>(*it);
      if(v && v->getRemake())
          videogames.push_back(v);
  }
  return videogames;
}

QList<Product*> productDatabase::videogameWithThisPEGI(int Pegi) const{
  QList<Product*> vv;
  for(auto it = products.begin() ; it != products.end(); ++it){
     Videogame* v = dynamic_cast<Videogame*>(*it);
     if(v && v->getPegi() == Pegi)
         vv.push_back(v);

  }
  return vv;
}

/***********  METODI DI RICERCA PER VIDEOGAME LIMITED  ***********/
QList<Product*> productDatabase::limitedVideogamewithExtraContents() const{
  QList<Product*> vl;
  for(auto it = products.begin() ; it != products.end(); ++it){
     Limited* l = dynamic_cast<Limited*>(*it);
     if(l && l->getExtracontents() != "nessuno")
         vl.push_back(l);
  }
  return vl; //Ritorna una lista di titoli che hanno il campo "ExtraContents" diverso da 'nessuno'
}


/***********  METODI DI RICERCA PER CONSOLE GENERALI  ***********/
QList<Product*> productDatabase::consoleSpecialEdition() const{
  QList<Product*> consoles;
  for(auto it = products.begin(); it !=products.end(); ++it){
      Console* c = dynamic_cast<Console*>(*it);
      if(c && c->getSpecialEdition())
          consoles.push_back(c);
  }
  return consoles;
}




