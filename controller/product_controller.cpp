#include "product_controller.h"
#include <QDebug>
product_Controller::product_Controller(productDatabase *dbProd, QObject *parent):  QObject(parent), allProducts(dbProd){}

void product_Controller::updateProduct_view(Productsettings *productview){
    viewProducts=productview;

    connect(viewProducts,SIGNAL(sendInsertVB(Product*,User*,QString,QString,QString, QString,QString,QString, bool,QString)),
    this,SLOT(getChanges_VB(Product*,User*,QString,QString,QString,QString,QString,QString,bool,QString)));

    connect(viewProducts,SIGNAL(sendInsertVL(Product*,User*,QString,QString, QString,QString,QString,QString,bool,bool,bool,bool,bool,QString,QString)),
    this,SLOT(getChanges_VL(Product*,User*,QString,QString,QString,QString,QString,QString,bool,bool,bool,bool,bool,QString,QString)));

    connect(viewProducts,SIGNAL(sendInsertCoNG(Product*,User*,QString,QString, QString, QString,QString,QString,QString,bool,bool)),
    this,SLOT(getChanges_CoNG(Product*,User*,QString,QString,QString,QString,QString,QString,QString, bool ,bool)));

    connect(viewProducts,SIGNAL(sendInsertCoRC(Product*,User*,QString,QString, QString, QString,QString,QString,QString,bool,QString)),
    this,SLOT(getChanges_CoRC(Product*,User*,QString,QString,QString,QString,QString,QString,QString,bool,QString)));

    connect(viewProducts,SIGNAL(sendDeleteProduct(Product*)),this,SLOT(getDelete(Product*)));
    connect(viewProducts,SIGNAL(sendNewProduct(Product*)),this,SLOT(getNewProduct(Product*)));
}

bool product_Controller::checkCommonFields(Product* prod, User* u, QString name, QString dev, QString pubb_d, bool mod){
  if(u->ModifyProducts()){ //Se l'utente può modificare il prodotto
  if(name != "" && name != prod->getName()){
  prod->setName(name); mod=true; }

  if(dev != "" && dev != prod->getDeveloper()){
  prod->setDeveloper(dev); mod=true; }

  if(pubb_d != "" && pubb_d != prod->getDate().toString("yyyy.MM.dd")){
  QDate dt = QDate::fromString(pubb_d,"yyyy.MM.dd");
  prod->setDate(dt); mod=true; }
}
  return mod;
}

void product_Controller::getChanges_VB(Product* prod, User* u,QString name,QString dev,QString pubb_d,QString PEGI,QString platform,
QString genre,bool remake,QString dim){
bool mod=false;

mod = checkCommonFields(prod, u, name, dev, pubb_d, mod);

if(PEGI != QString::number((dynamic_cast<Base*>(prod))->getPegi()) ){
  (dynamic_cast<Base*>(prod))->setPegi(PEGI.toInt()); mod=true; }
if(platform != (dynamic_cast<Base*>(prod))->getPlatform()){
  (dynamic_cast<Base*>(prod))->setPlatform(platform); mod=true; }
if(genre != (dynamic_cast<Base*>(prod))->getGenre()){
  (dynamic_cast<Base*>(prod))->setGenre(genre); mod=true; }
if(remake != (dynamic_cast<Base*>(prod))->getRemake()){
  (dynamic_cast<Base*>(prod))->setRemake(remake); mod=true; }
if(dim != "" && dim != QString::number((dynamic_cast<Base*>(prod))->getDim())){
  (dynamic_cast<Base*>(prod))->setDim(dim.toInt()); mod=true; }

  if(mod){
    QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
    allProducts->SaveAndClose();
    viewProducts->close();
  }

}


void product_Controller::getChanges_VL(Product *prod, User *u, QString name, QString dev, QString pubb_d, QString PEGI, QString platform,
QString genre, bool remake, bool steelbook, bool dlc, bool actionfigure, bool soundtrack, QString extrac, QString artbookp){
    bool mod=false;

mod = checkCommonFields(prod, u, name, dev, pubb_d, mod);

  if(PEGI != QString::number((dynamic_cast<Limited*>(prod))->getPegi()) ){
    (dynamic_cast<Limited*>(prod))->setPegi(PEGI.toInt()); mod=true; }
  if(platform != (dynamic_cast<Limited*>(prod))->getPlatform()){
    (dynamic_cast<Limited*>(prod))->setPlatform(platform); mod=true; }
  if(genre != (dynamic_cast<Limited*>(prod))->getGenre()){
    (dynamic_cast<Limited*>(prod))->setGenre(genre); mod=true; }
  if(remake != (dynamic_cast<Limited*>(prod))->getRemake()){
    (dynamic_cast<Limited*>(prod))->setRemake(remake); mod=true; }
  if(steelbook != (dynamic_cast<Limited*>(prod))->getSteelbook()){
    (dynamic_cast<Limited*>(prod))->setSteelbook(steelbook); mod=true; }
  if(dlc != (dynamic_cast<Limited*>(prod))->getDlc()){
    (dynamic_cast<Limited*>(prod))->setDlc(dlc); mod=true; }
  if(actionfigure != (dynamic_cast<Limited*>(prod))->getActionfigure()){
    (dynamic_cast<Limited*>(prod))->setActionfigure(actionfigure); mod=true; }
  if(soundtrack != (dynamic_cast<Limited*>(prod))->getSoundtrack()){
    (dynamic_cast<Limited*>(prod))->setSoundtrack(soundtrack); mod=true; }
  if(extrac !="" && extrac != (dynamic_cast<Limited*>(prod))->getExtracontents()){
    (dynamic_cast<Limited*>(prod))->setExtracontents(extrac); mod=true; }
  if(artbookp !="" && artbookp != QString::number((dynamic_cast<Limited*>(prod))->getArtbookpages())){
    (dynamic_cast<Limited*>(prod))->setArtbookpages(artbookp.toInt()); mod=true; }

  if(mod){
   QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
   allProducts->SaveAndClose();
   viewProducts->close(); }

}


void product_Controller::getChanges_CoNG(Product * prod, User * u, QString name, QString dev, QString pubb_d, QString controllertechtype,
QString hdd, QString maxres, QString consolecolor, bool specialedition, bool support4k){
bool mod=false;

mod = checkCommonFields(prod, u, name, dev, pubb_d, mod);

if(controllertechtype != (dynamic_cast<NewGeneration*>(prod))->getControllerTechType()){
    (dynamic_cast<NewGeneration*>(prod))->setControllerTechType(controllertechtype); mod=true; }
if(hdd != (dynamic_cast<NewGeneration*>(prod))->getHardDisk()){
    (dynamic_cast<NewGeneration*>(prod))->setHardDisk(hdd); mod=true; }
if(maxres != (dynamic_cast<NewGeneration*>(prod))->getMaxResolution()){
    (dynamic_cast<NewGeneration*>(prod))->setMaxResolution(maxres); mod=true; }
if(consolecolor != "" && consolecolor != (dynamic_cast<NewGeneration*>(prod))->getConsoleColor()){
    (dynamic_cast<NewGeneration*>(prod))->setConsoleColor(consolecolor); mod=true; }
if(specialedition != (dynamic_cast<NewGeneration*>(prod))->getSpecialEdition()){
    (dynamic_cast<NewGeneration*>(prod))->setSpecialEdition(specialedition); mod=true; }
if(support4k != (dynamic_cast<NewGeneration*>(prod))->getSupport4K()){
    (dynamic_cast<NewGeneration*>(prod))->setSupport4K(support4k); mod=true; }


    if (mod){
      QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
      allProducts->SaveAndClose();
      viewProducts->close();
    }
}

void product_Controller::getChanges_CoRC(Product *prod, User *u, QString name, QString dev, QString pubb_d,
QString controllertechtype, QString hdd, QString maxres, QString consolecolor, bool specialedition, QString bit){
bool mod=false;

mod = checkCommonFields(prod, u, name, dev, pubb_d, mod);

if(controllertechtype != (dynamic_cast<RetroConsole*>(prod))->getControllerTechType()){
    (dynamic_cast<RetroConsole*>(prod))->setControllerTechType(controllertechtype); mod=true; }
if(hdd != (dynamic_cast<RetroConsole*>(prod))->getHardDisk()){
    (dynamic_cast<RetroConsole*>(prod))->setHardDisk(hdd); mod=true; }
if(maxres != (dynamic_cast<RetroConsole*>(prod))->getMaxResolution()){
    (dynamic_cast<RetroConsole*>(prod))->setMaxResolution(maxres); mod=true; }
if(consolecolor != "" && consolecolor != (dynamic_cast<RetroConsole*>(prod))->getConsoleColor()){
    (dynamic_cast<RetroConsole*>(prod))->setConsoleColor(consolecolor); mod=true; }
if(specialedition != (dynamic_cast<RetroConsole*>(prod))->getSpecialEdition()){
    (dynamic_cast<RetroConsole*>(prod))->setSpecialEdition(specialedition); mod=true; }
if(bit != QString::number((dynamic_cast<RetroConsole*>(prod))->getBit())){
    (dynamic_cast<RetroConsole*>(prod))->setBit(bit.toInt()); mod=true; }

  if (mod){
  QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
  allProducts->SaveAndClose();
  viewProducts->close();
  }
}

void product_Controller::getDelete(Product *prod){
    viewProducts->close();
    allProducts->removeProductFromDB(prod);
    allProducts->SaveAndClose();
    QMessageBox::warning(0,"Eliminazione prodotto","Prodotto eliminato con successo!");
}

void product_Controller::getNewProduct(Product *prod){
        allProducts->addProductToDB(prod);
        viewProducts->close();
        allProducts->SaveAndClose();
        QMessageBox::information(0,"Aggiunta prodotto", "Aggiunta avvenuto con successo!");
}
