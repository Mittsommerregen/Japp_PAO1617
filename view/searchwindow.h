#ifndef SEARCHWINDOW
#define SEARCHWINDOW
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QComboBox>
#include<QHeaderView>
#include"../model/product_database.h"
#include"../model/user_database.h"
#include "list.h"
#include "productsettings.h"
#include "viewproduct.h"
#include "usersettings.h"

class DBSearch:public QWidget{
private:
    Q_OBJECT
    productDatabase * listProducts;
    userDatabase * listUsers;
    User * user; //utente che si loggerà
    QLabel * oppure;
    QPushButton * pushSearch;
    QPushButton * pushSearchUser;
    QPushButton * pushSearchProducts;
    QLineEdit * textSearch;
    QComboBox * searchFor; //argomento ricerca
    QPushButton * searchRemake;
    QLabel* pegi;
    QComboBox * searchPegi;
    QPushButton * searchExtraContents;
    QPushButton * searchSpecialEd;

    QGridLayout * gridSearch;
    QVBoxLayout * layoutSearch;
    DBList * table;
    Usersettings * info_user;
    Productsettings * info_product;
    viewProduct * view_product;


public:
    DBSearch(productDatabase * dbProd=0, userDatabase *dbUs=0, User * user=0, QWidget *parent =0);
    void newLayout();


public slots:
    void searchUSER();
    void searchPRODUCTS();
    void searchItem();
    void searchREMAKE();
    void searchPEGI();
    void searchSPECIALED();
    void searchEXTRAC();
    void doubleclick(int);
    void closeList();

signals:

    void savechanges_User(Usersettings*);
    void savechanges_Product(Productsettings*);
    void close_mainwindow();
};

#endif // SEARCHWINDOW

