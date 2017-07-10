#include <QApplication>
#include "model/user_database.h"
#include "model/product_database.h"
#include"controller/mainwindow_controller.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    mainwindowController mvc;
    mvc.Login();
    return a.exec();


}

