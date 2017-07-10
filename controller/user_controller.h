#ifndef USER_CONTROLLER
#define USER_CONTROLLER

#include"../model/user_database.h"
#include"view/usersettings.h"
#include<QObject>
#include<QMessageBox>

class user_Controller:public QObject{
private:
    Q_OBJECT
    userDatabase * allUsers;
    Usersettings * viewUsers;

public:
    user_Controller(userDatabase * dbUser, QObject* parent=0);
    void updateUser_view(Usersettings * userview);

public slots:
    void addUser_controller(User *us);
    void getChanges_User(User *us, QString nickname, QString pass, QString nome, QString cognome, QString tipo);
    void getDelete_User(User *us);
};

#endif // USER_CONTROLLER

