#ifndef LIST
#define LIST

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include"../model/user_database.h"
#include"../model/product_database.h"
#include"usersettings.h"


class DBList:public QTableWidget{
 private:
    Q_OBJECT
    productDatabase * productlist;
    userDatabase * userlist;
public:
    DBList(productDatabase *productdb, userDatabase* userdb, QWidget *parent=0);
    void viewUsers();
    void addListUsers(User *user);
    void addListUsers(QList<User*>);
    void addListAllUsers();
    void addItemUser(int row, User *u);

    void viewProducts();
    void addListProducts(Product *p);
    void addListProducts(QList<Product*>);
    void addListAllProducts();
    void addItemProduct(int r, Product *p);

signals:
   void clicked(int,int);
};
#endif //LIST
