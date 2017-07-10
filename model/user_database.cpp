#include "user_database.h"
QString userDatabase::filename="../ProgettoP2/model/userDatabase.xml";

userDatabase::userDatabase(){
    Load();
}

userDatabase::~userDatabase(){
    SaveAndClose();
    auto it=users.begin();
    for( ; it!=users.end(); ++it){
        delete *it;
        it=users.erase(it);
        it--;
    }
}


User *userDatabase::getUser(const QString &text) {
    User* result =nullptr;
    auto it=users.begin();
    for( ;it!=users.end(); ++it){
       if((*it)->getNickname() == text ){
          result= *it;
       }
    }
    return result;
}

 QList<User*> userDatabase::userContainsWord(const QString & word) const{
    QList<User*> temp;   bool result=false;
    for(auto it=users.begin(); it!=users.end(); ++it){
    if((*it)->getNickname().contains(word, Qt::CaseInsensitive) || (*it)->getName().contains(word, Qt::CaseInsensitive) ||
        (*it)->getSurname().contains(word, Qt::CaseInsensitive)){
        temp.push_back(*it);
        result=true;
      }
    }
     if(result == false)
        QMessageBox::warning(0,"Attenzione","Nessun risultato, riprova!");

    return temp;
}
/*
bool userDatabase::isEmpty() const{
    if(users.size()==0) return true;
    return false;
}*/

bool userDatabase::findNickname(const QString &nickname){
 bool found=false;
 auto it=users.begin();
 for(; it!=users.end() && !found ; ++it){
     if((*it)->getNickname()==nickname){
         found=true;
     }
 }
 return found;
}

User* userDatabase::checkUser(const QString &nickname, const QString &password){
    User* loggeduser=nullptr;

    bool checkadmin=false;
    auto it=users.begin();
    for(; it!=users.end(); ++it){

        if(((*it)->getNickname()==nickname) && ((*it)->getPassword()==password))
            loggeduser=(*it);

        if((*it)->getLabel() =="Admin")
            checkadmin=true;
    }
    //Se eseguo accesso con db vuoto
    if(!checkadmin){
        if(("admin"==nickname)&&("admin"==password)){
            loggeduser=new User_Admin("admin","admin");
            users.push_back(loggeduser);
        }
    }
    return loggeduser;
}

void userDatabase::upgradeUserCategory(User *u, QString c){
    User *temp =nullptr;

    if(c=="Admin")
        temp=new User_Admin(u->getNickname(),u->getPassword(), u->getName(), u->getSurname());

    if(c =="UserBase")
    temp=new User_Base(u->getNickname(),u->getPassword(), u->getName(), u->getSurname());

     if(c =="UserPremium")
            temp=new User_Premium(u->getNickname(),u->getPassword(), u->getName(), u->getSurname());



    if(temp){
        removeUserToDB(u);
        users.push_back(temp);
        SaveAndClose();
    }
}

void userDatabase::addUserToDB(User *u){
  User* usertoadd=getUser(u->getNickname());
  if(usertoadd){
      QMessageBox::warning(0,"Errore inserimento utente", "Ops! Qualcuno ha già preso questo nickname! Scegline uno diverso.");
      delete u;
      u=nullptr;
  }
  else{
     users.push_back(u);
     QMessageBox::information(0,"Inserimento utente", "Inserimento avvenuto con successo!");
     SaveAndClose();
  }
}

void userDatabase::removeUserToDB(User *u){
    auto it=users.begin();
    for(; it!=users.end(); ++it){
        if((*it)->getNickname()==u->getNickname()){
            delete *it;
            it=users.erase(it);
            it--;
        }
    }
}

const QList<User*> userDatabase::getAllUsers() const{
    QList<User*> u;
    for(auto it=users.begin();it!=users.end();++it){
        u.push_back(*it);
    }
    return u;
}


void userDatabase::Load() {
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();
        while(!xmlReader.atEnd()){
            User* u=nullptr;
            if(xmlReader.name()=="Admin") u=new User_Admin;
            else if(xmlReader.name()=="UserBase") u=new User_Base;
            else if(xmlReader.name()=="UserPremium") u=new User_Premium;

            if(u){
                u->loadUser(xmlReader);
                users.push_back(u);
            }

            xmlReader.readNextStartElement();
        }
    }
    else{
        QMessageBox::warning(0,"File mancanti","Creazione file di default");
    }

}

void userDatabase::SaveAndClose(){
    QFile file(filename);
  //  if(!file.exists()){
//   filename = QFileDialog::getSaveFileName((QWidget* )0,"Crea database Xml in cui salvare i dati", ".","Xml files (*.xml)");
  //    }
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Utenti");
    auto it=users.begin();
    for(; it!=users.end(); ++it){
        (*it)->saveUser(xmlWriter);
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();    
}

