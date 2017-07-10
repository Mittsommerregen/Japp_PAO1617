#ifndef MAINWINDOW
#define MAINWINDOW
#include<QMainWindow>
#include<QPixmap>
#include<QIcon>
#include<QMenuBar>
#include<QAction>
#include<QApplication>
#include<QDesktopWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMainWindow>

#include "../model/user_database.h"
#include "../model/product_database.h"
#include "searchwindow.h"
#include "usersettings.h"

class MainWindow : public QMainWindow{
private:
     Q_OBJECT
  userDatabase* allUsers;
  productDatabase* allProducts;
  User* user;

  QMenu * menuOptions;
  QAction * menuAccountSettings;
  QAction * menuLogout;

  QMenu * menuSettings;
  QAction * menuUserSettings;
  QAction * menuProductSettings;

  QMenu * menuInfo;
  QAction * menuInfoclick;

  QPushButton * modify;
  QPixmap * infoIcon;
  DBSearch* searchfromDB;

  Usersettings * viewUserSettings;
  Usersettings * viewAccountSettings; //personal account
  Productsettings * viewProductSettings;

public:
    MainWindow(userDatabase * dbus=0, productDatabase *dbprod=0, User*u=0, QWidget *parent =0);
    void setMenuOptions(); //visualizza menu a tendina
    void doSearch();
    void openSettings();

public slots:
    void openUserSettings();    //Apertura impostazioni utenti
    void openAccountSettings(); //Apertura impostazioni account personale
    void openProductSettings(); //Apertura impostazioni prodotti
    void updateAccountSettings(Usersettings * userprofile);
    void closeWindows();
    void closeSession(); //Chiusura sessione
private slots:
     void openInfo();
signals:
    void closeMainWindow();
    void doLogout();
    void updateUserSettings(Usersettings*);
    void updateProductSettings(Productsettings*);

};

#endif // MAINWINDOW
