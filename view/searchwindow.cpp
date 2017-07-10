#include "searchwindow.h"
#include "QDebug"
DBSearch::DBSearch(productDatabase * dbProd, userDatabase *dbUs, User * user, QWidget *parent):
     QWidget(parent), listProducts(dbProd), listUsers(dbUs), user(user){
    this->setAttribute(Qt::WA_DeleteOnClose);
    table=nullptr;
    info_user=nullptr;
    info_product=nullptr;
    newLayout();
}

void DBSearch::newLayout(){
  /* VIEW COMUNE A TUTTI GLI UTENTI: INTERROGAZIONI BASE AL DATABASE */
  pushSearchProducts=new QPushButton("Visualizza tutti i prodotti");
  pushSearchProducts->setFixedWidth(300);
  pushSearchProducts->setFixedHeight(40);
  pushSearchUser=new QPushButton("Visualizza tutti gli utenti");
  pushSearchUser->setFixedWidth(300);
  pushSearchUser->setFixedHeight(40);
  oppure = new QLabel("oppure");
  oppure->setAlignment(Qt::AlignCenter);
  textSearch=new QLineEdit();
  textSearch->setFixedWidth(300);
  textSearch->setPlaceholderText("Inserisci testo da ricercare");
  searchFor=new QComboBox();
  searchFor->addItem("Prodotti");
  searchFor->addItem("Utenti");
  searchFor->setFixedWidth(140);
  pushSearch=new QPushButton("Cerca");
  pushSearch->setFixedWidth(150);
  pushSearch->setFixedHeight(40);


  /*VIEW RISERVATA A USER PREMIUM */
  if(user->premiumFunctions()){
  searchSpecialEd=new QPushButton("Consoles in Ed. Speciale");
  searchSpecialEd->setFixedWidth(300);
  searchExtraContents=new QPushButton("Videogames con contenuto extra");
  searchExtraContents->setFixedWidth(300);
  searchRemake=new QPushButton("Videogames versione Remake");
  searchRemake->setFixedWidth(300);
  pegi=new QLabel("Cerca videogames per PEGI:");
  searchPegi=new QComboBox();
  searchPegi->addItem("3");
  searchPegi->addItem("7");
  searchPegi->addItem("12");
  searchPegi->addItem("16");
  searchPegi->addItem("18");
  searchPegi->setFixedWidth(60);
  }


   /* VIEW COMUNE PER TABELLA */
   table= new DBList (listProducts, listUsers,this);
   table->setMaximumHeight(600);
   table->setMaximumWidth(917);
   connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleclick(int)));

    gridSearch=new QGridLayout();
    gridSearch->addWidget(pushSearchProducts,0,0);
    gridSearch->addWidget(pushSearchUser,0,1);
    gridSearch->addWidget(oppure,0,2);
    gridSearch->addWidget(textSearch,0,3);
    gridSearch->addWidget(searchFor,0,4);
    gridSearch->addWidget(pushSearch,0,5);
    if(user->premiumFunctions()){
    gridSearch->addWidget(searchSpecialEd,1,0);
    gridSearch->addWidget(searchExtraContents,1,1);
    gridSearch->addWidget(searchRemake,1,3);
    gridSearch->addWidget(pegi, 1,4);
    gridSearch->addWidget(searchPegi, 1,5);
    connect(searchRemake,SIGNAL(clicked(bool)),this,SLOT(searchREMAKE()));
    connect(searchSpecialEd,SIGNAL(clicked(bool)),this,SLOT(searchSPECIALED()));
    connect(searchPegi,SIGNAL(activated(int)),this,SLOT(searchPEGI()));
    connect(searchExtraContents,SIGNAL(clicked(bool)),this,SLOT(searchEXTRAC()));
    }
    gridSearch->addWidget(table,4,1,3,8);

    layoutSearch=new QVBoxLayout();
    layoutSearch->addLayout(gridSearch);

    connect(pushSearch,SIGNAL(clicked(bool)),this,SLOT(searchItem()));
    connect(pushSearchProducts,SIGNAL(clicked(bool)),this,SLOT(searchPRODUCTS())); //Ricerca tutti i prodotti
    connect(pushSearchUser,SIGNAL(clicked(bool)),this,SLOT(searchUSER())); //Ricerca tutti gli utenti
    setLayout(layoutSearch);
    table->close();
}

void DBSearch::closeList(){
    table->close();
}

void DBSearch::searchREMAKE(){
  textSearch->clear();
  table->viewProducts();
  table->addListProducts(listProducts->videogameRemake());
  table->verticalHeader()->hide();
  table->show();
}


void DBSearch::searchSPECIALED(){
  textSearch->clear();
  table->viewProducts();
  table->addListProducts(listProducts->consoleSpecialEdition());
  table->verticalHeader()->hide();
  table->show();
}

void DBSearch::searchPEGI(){
  textSearch->clear();
  table->viewProducts();
  table->addListProducts(listProducts->videogameWithThisPEGI(searchPegi->currentText().toInt()));
  table->verticalHeader()->hide();
  table->show();
}

void DBSearch::searchEXTRAC(){
  textSearch->clear();
  table->viewProducts();
  table->addListProducts(listProducts->limitedVideogamewithExtraContents());
  table->verticalHeader()->hide();
  table->show();
}


void DBSearch::searchUSER(){
    textSearch->clear();
    table->viewUsers();
    table->addListAllUsers();
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::searchPRODUCTS(){
    textSearch->clear();
    table->viewProducts();
    table->addListAllProducts();
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::searchItem(){
  QString text_entered=textSearch->text();
  table->clear();
  if(text_entered != ""){
  if(searchFor->currentText()=="Utenti"){
    table->viewUsers();
    table->addListUsers(listUsers->userContainsWord(text_entered));}
  else{
    if(searchFor->currentText()=="Prodotti"){
    table->viewProducts();
    table->addListProducts(listProducts->productContainsWord(text_entered)); }
  }
} else { //Sto cercando con il campo vuoto
     table->setColumnCount(0);
    QMessageBox::warning(0,"Attenzione nella ricerca","Digitare il testo da ricercare");
      }
  table->verticalHeader()->hide();
  table->show();
  textSearch->clear();
}

void DBSearch::doubleclick(int x){
    //SE SONO NELLA LISTA UTENTI
   if(table->horizontalHeaderItem(0)->text()=="Nickname" && user->getLabel()=="Admin"){
   User* modifyUser=listUsers->getUser((table->item(x,0))->text());
   info_user=new Usersettings(user,modifyUser);
   connect(info_user,SIGNAL(sendDelete(User*)),this,SLOT(closeList()));
   connect(info_user,SIGNAL(sendChanges(User*,QString,QString,QString,QString,QString)),this,SLOT(closeList()));
   emit close_mainwindow();
   connect(info_user,SIGNAL(finished(int)),this,SIGNAL(close_mainwindow()));
   info_user->setModLayout();
   info_user->show();
   emit savechanges_User(info_user);
    }
   //SE SONO NELLA LISTA PRODOTTI
   if(table->horizontalHeaderItem(0)->text()=="Nome" && user->ModifyProducts()){
  Product* modifyProduct=listProducts->getProduct((table->item(x,3))->text().toInt());
  info_product=new Productsettings(user,modifyProduct);
   emit close_mainwindow();
  connect(info_product,SIGNAL(sendDeleteProduct(Product*)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(sendNewProduct(Product*)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(sendInsertVB(Product*,User*,QString,QString,QString,QString,QString, QString, bool,QString)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(sendInsertVL(Product*,User*,QString,QString,QString,QString,QString, QString, bool,bool,bool,bool,bool,QString,QString)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(sendInsertCoNG(Product*,User*,QString,QString,QString,QString,QString,QString,QString,bool, bool)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(sendInsertCoRC(Product*,User*,QString,QString,QString,QString,QString,QString,QString,bool, QString)),this,SLOT(closeList()));
  connect(info_product,SIGNAL(finished(int)),this,SIGNAL(close_mainwindow()));
  info_product->setModLayout();
  info_product->show();
  emit savechanges_Product(info_product);
    }
    //SE SONO UN UTENTE BASE
   else if(table->horizontalHeaderItem(0)->text()=="Nome"){
   Product* product=listProducts->getProduct((table->item(x,3))->text().toInt());
   view_product = new viewProduct(product);
   view_product->addLayout();
   view_product->show();
   //emit close_mainwindow();
}
}

