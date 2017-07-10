#ifndef MAINWINDOW_CONTROLLER
#define MAINWINDOW_CONTROLLER

#include"../model/product_database.h"
#include"../model/user_database.h"
#include<QObject>
#include"../view/loginwindow.h"
#include"../view/mainwindow.h"
#include"user_controller.h"
#include"product_controller.h"

#include<QMessageBox>

class mainwindowController:public QObject{
private:
    Q_OBJECT
    productDatabase * allProduts;
    userDatabase *allUsers;
    User* loggeduser;

    LoginWindow * login;
    MainWindow * mainwindow;

    user_Controller *userController;
    product_Controller *productController;


public:
    mainwindowController(QObject *parent =0);
    ~mainwindowController();
    void Login();

public slots:
     void doLoginController(const QString &nickname, const QString &password);
     void updateLogin();
     void updateUserController(Usersettings * viewus);
     void updateProductController(Productsettings* viewprod);

};


#endif // MAINWINDOW_CONTROLLER

