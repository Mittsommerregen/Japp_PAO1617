#include "mainwindow_controller.h"


mainwindowController::mainwindowController(QObject *parent):QObject(parent){
    login=nullptr;
    userController=nullptr;
    productController=nullptr;

    mainwindow=nullptr;
    allProduts= new productDatabase();
    allUsers = new userDatabase();
}

mainwindowController::~mainwindowController(){
    delete allProduts;
    delete allUsers;
 }

void mainwindowController::Login(){
    login=new LoginWindow();
    connect(login,SIGNAL(doLogin(QString,QString)),this,SLOT(doLoginController(QString,QString)));
    login->show();
    userController=new user_Controller(allUsers,this);
    productController=new product_Controller(allProduts,this);
}

void mainwindowController::doLoginController(const QString &nickname, const QString &password){
    loggeduser=allUsers->checkUser(nickname,password);
    if(!loggeduser){
        QMessageBox::warning(0,"Errore login", "Errore con le credenziali, riprova!");
        login->empty();
    }
    else{
        mainwindow = new MainWindow(allUsers,allProduts,loggeduser);
        connect(mainwindow,SIGNAL(doLogout()),this,SLOT(updateLogin()));
        connect(mainwindow,SIGNAL(updateUserSettings(Usersettings*)),this,SLOT(updateUserController(Usersettings *)));
        connect(mainwindow,SIGNAL(updateProductSettings(Productsettings*)),this,SLOT(updateProductController(Productsettings*)));

        login->close();
        login=nullptr;
        mainwindow->show();
    }
}

void mainwindowController::updateLogin(){
    if(!login)
    login=new LoginWindow();
    //Se invece il login va a buon fine
    connect(login,SIGNAL(doLogin(QString,QString)),this,SLOT(doLoginController(QString,QString)));
    login->empty();
    login->show();
}

void mainwindowController::updateUserController(Usersettings * viewus){
    userController->updateUser_view(viewus);
}

void mainwindowController::updateProductController(Productsettings* viewprod){
    productController->updateProduct_view(viewprod);
}



