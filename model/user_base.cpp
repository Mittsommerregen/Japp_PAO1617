#include "user_base.h"
#include "math.h"

User_Base::User_Base(const QString& _nick, const QString& _pw, const QString& _name, const QString& _surname):
User(_nick,_pw, _name, _surname){}

QString User_Base::getLabel() const{
   return "UserBase";
}
bool User_Base::ModifyUsers() const{
    return false;
}

bool User_Base::ModifyProducts() const{
    return false;
}

bool User_Base::premiumFunctions() const{
  return false;
}
