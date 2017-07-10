#ifndef PRODUCT_CONTROLLER
#define PRODUCT_CONTROLLER

#include"../model/product_database.h"
#include"../view/productsettings.h"
#include<QObject>
#include<QMessageBox>

class product_Controller:public QObject{
private:
    Q_OBJECT
    productDatabase * allProducts;
    Productsettings * viewProducts;
public:
  product_Controller(productDatabase * dbProduct, QObject* parent=0);
  void updateProduct_view(Productsettings* productview);
  bool checkCommonFields(Product*, User*, QString, QString, QString, bool);
 public slots:  
  //Modifica su Videogioco Base
  void getChanges_VB(Product*,User*,QString,QString,QString, QString,QString,QString, bool,QString);

  //Modifica su Videogioco Limited
  void getChanges_VL(Product*,User*,QString,QString, QString,QString,QString,QString,bool,bool,bool,bool,bool,QString,QString);

  //Modifica su Console Nuova Generazione
  void getChanges_CoNG(Product*,User*,QString,QString, QString, QString,QString,QString,QString,bool,bool);

  //Modifica su Retro Console
  void getChanges_CoRC(Product*,User*,QString,QString, QString, QString,QString,QString,QString,bool,QString);

  void getDelete(Product *prod);
  void getNewProduct(Product *prod);
};

#endif // PRODUCT_CONTROLLER

