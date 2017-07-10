#include "usersettings.h"
Usersettings::Usersettings(User *user, User *editedus):user(user),editeduser(editedus){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Impostazioni Utente");
    addModLayout();
}

void Usersettings::addModLayout(){
    labelName=new QLabel("Nome");
    labelSurname=new QLabel("Cognome");
    labelNickname=new QLabel("Nickname");
    labelPassword=new QLabel("Password");
    Type=new QLabel("Tipologia Account");

    labelType=new QLabel(editeduser->getLabel());
    textName=new QLineEdit();
    textName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z\\s]{1,15}")));
    textSurname=new QLineEdit();
    textSurname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z\\s]{1,15}")));
    textNickname=new QLineEdit();
    textNickname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    textPassword=new QLineEdit();
    textPassword->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    selectType=new QComboBox();
    selectType->addItem("UserBase");
    selectType->addItem("UserPremium");
    selectType->addItem("Admin");

    //Restituisce l'indice del corrispondente testo
    int index= selectType->findText(editeduser->getLabel());
    //Setta all'indice corretto
    selectType->setCurrentIndex(index);
    //Dato l'indice ritorna il testo corrispondente
    selectType->itemText(index);

    textName->setPlaceholderText("Inserisci nome");
    textSurname->setPlaceholderText("Inserisci cognome");
    textNickname->setPlaceholderText("Inserisci nickname");
    textPassword->setPlaceholderText("Inserisci password");

    textNickname->setText(editeduser->getNickname());
    textPassword->setText(editeduser->getPassword());
    textName->setText(editeduser->getName());
    textSurname->setText(editeduser->getSurname());

    pushModify=new QPushButton("Salva le modifiche effettuate");
    pushDelete=new QPushButton("Elimina l'utente");
    pushAdd=new QPushButton("Aggiungi utente");

    /******************  GRIDLAYOUT   ********************/
    gridUserSettings=new QGridLayout;
    gridUserSettings->addWidget(labelNickname,0,0);
    gridUserSettings->addWidget(labelPassword,1,0);
    gridUserSettings->addWidget(labelName,2,0);
    gridUserSettings->addWidget(labelSurname,3,0);

    gridUserSettings->addWidget(textNickname,0,1);
    gridUserSettings->addWidget(textPassword,1,1);
    gridUserSettings->addWidget(textName,2,1);
    gridUserSettings->addWidget(textSurname,3,1);

    gridUserSettings->addWidget(Type,4,0);
    gridUserSettings->addWidget(selectType,4,1);
    gridUserSettings->addWidget(labelType,4,1);
    gridUserSettings->addWidget(pushModify,6,0);
    gridUserSettings->addWidget(pushDelete,6,1);
    gridUserSettings->addWidget(pushAdd,7,0);

    layoutUserSettings=new QVBoxLayout();
    layoutUserSettings->addLayout(gridUserSettings);

    connect(pushModify,SIGNAL(clicked()),this,SLOT(save_change_user()));
    connect(pushAdd,SIGNAL(clicked()),this,SLOT(addUser()));
    connect(pushDelete,SIGNAL(clicked()),this,SLOT(save_delete()));
    setLayout(layoutUserSettings);
}

void Usersettings::setModLayout(){
    pushAdd->hide();
    if(user->ModifyUsers() && user->getNickname() !=  editeduser->getNickname()){
    textPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    labelType->hide();
    }
    else{
     selectType->hide();
     pushDelete->hide();
    }
}

void Usersettings::changeNickname(){
    textNickname->clear();
    textNickname->setText(editeduser->getNickname());
    textNickname->setFocus();
}

void Usersettings::empty(){
    textPassword->clear();
    textNickname->clear();
    textName->clear();
    textSurname->clear();
    textNickname->setFocus();
}

void Usersettings::setLayoutAdd(){
    pushAdd->show();
    pushDelete->hide();
    pushModify->hide();
    labelType->hide();
    selectType->show();
    this->empty();
}

void Usersettings::save_change_user(){
    if(textNickname->text() != "" && textPassword->text() != "" && textName->text() != "" && textSurname->text() != ""){
     emit sendChanges(editeduser,textNickname->text(),textPassword->text(),
     textName->text(), textSurname->text(), selectType->currentText());
    }
    else{
        textNickname->setText(editeduser->getNickname());
        textPassword->setText(editeduser->getPassword());
        textName->setText(editeduser->getName());
        textSurname->setText(editeduser->getSurname());
        QMessageBox::warning(0,"Modifiche fallite","Compilare tutti i campi");
    }
}

void Usersettings::addUser(){
   if(textNickname->text() != "" && textPassword->text() != "" && textName->text() != "" && textSurname->text() != ""){
     User *generalUser=nullptr;
     if(selectType->currentText()=="UserBase")
     generalUser= new User_Base(textNickname->text(),textPassword->text(), textName->text(),textSurname->text());

     else if(selectType->currentText()=="UserPremium")
     generalUser= new User_Premium(textNickname->text(),textPassword->text(), textName->text(),textSurname->text());

     else if(selectType->currentText()=="Admin")
     generalUser= new User_Admin(textNickname->text(),textPassword->text(), textName->text(),textSurname->text());

     emit thisUser(generalUser);
 }
 else
     QMessageBox::warning(0,"Attenzione","È necessario riempire tutti i campi dati");

}

void Usersettings::save_delete(){
    emit sendDelete(editeduser);
    if(user==editeduser){
        emit logout();
    }
    this->close();
}
