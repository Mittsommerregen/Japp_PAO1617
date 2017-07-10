#include "user.h"

User::User(const QString& _nick, const QString& _pw, const QString &_name, const QString &_surname): nickname(_nick), password(_pw), name(_name), surname(_surname){}

QString User::getNickname() const {
return nickname;
}

void User::setNickname(const QString& newNickname){
    nickname = newNickname;
}

void User::setPassword(const QString& newPassword){
    password = newPassword;
}

QString User::getPassword() const {
    return password;
}

QString User::getName() const {
return name;
}

QString User::getSurname() const {
return surname;
}

void User::setName(const QString& newName){
    name = newName;
}

void User::setSurname(const QString& newSurname){
    surname = newSurname;
}


void User::saveCommonFieldsUser(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeTextElement("Nickname",getNickname());
    xmlWriter.writeTextElement("Password",getPassword());
    xmlWriter.writeTextElement("Nome",getName());
    xmlWriter.writeTextElement("Cognome",getSurname());
}

void User::loadCommonFieldsUser(QXmlStreamReader &xmlReader){
    xmlReader.readNextStartElement();
    if(xmlReader.name()=="Nickname") {
        setNickname(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Password") {
        setPassword(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Nome") {
        setName(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Cognome") {
        setSurname(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
}

void User::saveUser(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeStartElement(getLabel());
    saveCommonFieldsUser(xmlWriter);
}

void User::loadUser(QXmlStreamReader &xmlReader){
    loadCommonFieldsUser(xmlReader);
}
