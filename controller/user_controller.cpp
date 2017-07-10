#include "user_controller.h"

user_Controller::user_Controller(userDatabase *dbUser, QObject *parent):QObject(parent), allUsers(dbUser) {
    viewUsers=nullptr;
}

void user_Controller::updateUser_view(Usersettings *usv){
    viewUsers=usv;
    connect(viewUsers,SIGNAL(thisUser(User*)),this,SLOT(addUser_controller(User*)));
    connect(viewUsers,SIGNAL(sendChanges(User*,QString,QString,QString,QString,QString)),this,SLOT(getChanges_User(User*,QString,QString,QString,QString,QString)));
    connect(viewUsers,SIGNAL(sendDelete(User*)),this,SLOT(getDelete_User(User*)));
}

void user_Controller::addUser_controller(User *u){
    viewUsers->empty();
    allUsers->addUserToDB(u);
}

void user_Controller::getChanges_User(User * us,  QString nickname, QString password, QString name, QString surname, QString type){
    if(us->getNickname() != nickname && allUsers->findNickname(nickname)){
        viewUsers->changeNickname();
        QMessageBox::information(0,"Modifiche utente", "Qualcuno ha già scelto questo nickname! Inserire un nickname diverso.");

    }
    else{
        us->setNickname(nickname);
        us->setPassword(password);
        us->setName(name);
        us->setSurname(surname);

        if(type != us->getLabel()){
            allUsers->upgradeUserCategory(us,type);
        }
        QMessageBox::information(0,"Modifiche utente", "Modifiche utente avvenute correttamente");
        allUsers->SaveAndClose();
        viewUsers->close();
    }
}

void user_Controller::getDelete_User(User *us){
    allUsers->removeUserToDB(us);
    allUsers->SaveAndClose();
    QMessageBox::warning(0,"Eliminazione utente","Utente eliminato con successo!");
}
