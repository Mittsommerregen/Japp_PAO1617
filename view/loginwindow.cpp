#include "loginwindow.h"
#include <QPixmap>

LoginWindow::LoginWindow(){
    this->setAttribute(Qt::WA_DeleteOnClose); //distruzione
    setWindowTitle("Pannello login");

    //Inserimento icona
    windowIcon = new QLabel();
    windowIcon->setAlignment(Qt::AlignCenter);
    QPixmap image(":/icon.png");
    windowIcon->setPixmap(image.scaled(500,500,Qt::KeepAspectRatio));

    labelNickname=new QLabel("Nickname:");
    labelPassword=new QLabel("Password:");
    textNickname=new QLineEdit();
    textPassword=new QLineEdit();
    textNickname->setPlaceholderText("Inserisci nickname");
    textPassword->setPlaceholderText("Inserisci password");
    textNickname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    //I caratteri nella password non vengono visualizzati
    textPassword->setEchoMode(QLineEdit::Password);

    pushLogin=new QPushButton("Login");
    gridLogin=new QGridLayout;
    gridLogin->addWidget(windowIcon);
    gridLogin->addWidget(labelNickname);
    gridLogin->addWidget(textNickname);
    gridLogin->addWidget(labelPassword);
    gridLogin->addWidget(textPassword);
    gridLogin->addWidget(pushLogin);
    layoutLogin=new QVBoxLayout();
    layoutLogin->addLayout(gridLogin);
    setLayout(layoutLogin);
    connect(pushLogin,SIGNAL(clicked()),this,SLOT(login()));
}

void LoginWindow::login(){
    emit doLogin(textNickname->text(),textPassword->text());
}


void LoginWindow::empty(){
    textNickname->clear();
    textPassword->clear();
    textNickname->setFocus();
}
