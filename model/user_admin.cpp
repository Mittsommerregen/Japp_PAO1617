#include "user_admin.h"
#include <QDebug>

User_Admin::User_Admin(const QString& _nick, const QString& _pw, const QString& _name, const QString& _surname): User(_nick,_pw, _name, _surname){}

bool User_Admin::ModifyUsers() const{
    return true;
}

bool User_Admin::ModifyProducts() const{
    return true;
}

bool User_Admin::premiumFunctions() const{
  return false;
}
QString User_Admin::getLabel() const{
   return "Admin";
}



