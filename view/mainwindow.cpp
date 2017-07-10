#include "mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(userDatabase *dbus, productDatabase *dbprod, User*u, QWidget *parent):
    QMainWindow(parent),allUsers(dbus), allProducts(dbprod), user(u){
   this->setAttribute(Qt::WA_DeleteOnClose);
   setWindowTitle("Japp - Games & Consoles");

   //Setta le dimensioni della MainWindow
   setFixedHeight(700);
   setFixedWidth(1400);

   //Centra la MainWindow
   QRect wmainPosition = geometry();
   wmainPosition.moveCenter(QApplication::desktop()->availableGeometry().center());
   setGeometry(wmainPosition);

   setMenuOptions();
   searchfromDB=nullptr;
   viewUserSettings=nullptr;
   viewAccountSettings=nullptr;
   viewProductSettings=nullptr;
   doSearch();
}

void MainWindow::setMenuOptions(){
    menuOptions=new QMenu("Profilo",this);
    menuAccountSettings=new QAction("Impostazioni personali",this);
    menuLogout=new QAction("Exit",this);
    menuOptions->addAction(menuAccountSettings);
    menuOptions->addAction(menuLogout);

    connect(menuAccountSettings,SIGNAL(triggered(bool)),this,SLOT(openAccountSettings()));
    connect(menuLogout,SIGNAL(triggered(bool)),this,SLOT(closeSession()));

    menuBar()->addMenu(menuOptions);

    menuSettings=new QMenu("Aggiungi",this);
    //Controlla che l'utente loggato può effettuare la gestione degli utenti
    if(user->ModifyUsers()){

        menuUserSettings=new QAction("Utente",this);
        menuSettings->addAction(menuUserSettings);
        connect(menuUserSettings,SIGNAL(triggered(bool)),this,SLOT(openUserSettings()));
        menuBar()->addMenu(menuSettings);
    }
    //Controlla che l'utente loggato può effettuare la gestione dei prodotti
    if(user->ModifyProducts()){
        menuProductSettings=new QAction("Prodotto", this);
        menuSettings->addAction(menuProductSettings);
        connect(menuProductSettings,SIGNAL(triggered(bool)),this,SLOT(openProductSettings()));
        menuBar()->addMenu(menuSettings);
    }

    menuInfo=new QMenu("Info",this);
    menuInfoclick=new QAction("About Japp..", this);
    menuInfo->addAction(menuInfoclick);
    menuBar()->addMenu(menuInfo);
    connect(menuInfoclick, SIGNAL(triggered(bool)),this,SLOT(openInfo()));
 }


void MainWindow::openInfo(){
  QMessageBox info;
  info.setWindowFlags(Qt::WindowTitleHint);
  infoIcon = new QPixmap();
  info.setWindowTitle("Informazioni sullo sviluppatore");
  infoIcon->load(":/avatar.png");
  info.setIconPixmap(*infoIcon);
  info.setDetailedText("Japp - Games & Consoles è un'applicazione creata da Giulia Amato.");
  info.exec();
}

void MainWindow::doSearch(){
    searchfromDB=new DBSearch(allProducts, allUsers, user);
    connect(searchfromDB,SIGNAL(close_mainwindow()),this,SLOT(closeWindows()));
    connect(searchfromDB, SIGNAL(savechanges_User(Usersettings*)),this,SLOT(updateAccountSettings(Usersettings*)));
    connect(searchfromDB,SIGNAL(savechanges_Product(Productsettings*)),this,SIGNAL(updateProductSettings(Productsettings*)));
    setCentralWidget(searchfromDB);
}

void MainWindow::openUserSettings(){
    openSettings();
    viewAccountSettings->setLayoutAdd();
    viewAccountSettings->show();
}

void MainWindow::openSettings(){
    viewAccountSettings=new Usersettings(user,user);
    closeWindows();
    connect(viewAccountSettings,SIGNAL(finished(int)),this,SLOT(closeWindows()));
    emit(updateUserSettings(viewAccountSettings));
    connect(viewAccountSettings,SIGNAL(logout()),this,SLOT(closeSession()));
    searchfromDB->closeList();
}

void MainWindow::openAccountSettings(){
    openSettings();
    viewAccountSettings->setModLayout();
    viewAccountSettings->show();
}

void MainWindow::openProductSettings(){
    viewProductSettings=new Productsettings(user);
    closeWindows();
    connect(viewProductSettings,SIGNAL(finished(int)),this,SLOT(closeWindows()));
    emit(updateProductSettings(viewProductSettings));
    viewProductSettings->setNewLayout();
    viewProductSettings->show();
    searchfromDB->closeList();
}

void MainWindow::updateAccountSettings(Usersettings *userprofile){
    connect(userprofile, SIGNAL(logout()),this,SLOT(closeSession()));
    emit updateUserSettings(userprofile);
}

void MainWindow::closeSession(){
    emit doLogout();
    this->close();
}

void MainWindow::closeWindows(){
    if(isEnabled())
        this->setEnabled(0);
    else
        this->setEnabled(1);  
}




