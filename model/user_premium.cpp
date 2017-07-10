#include "user_premium.h"

User_Premium::User_Premium(const QString& _nick, const QString& _pw, const QString& _name, const QString& _surname):
User_Base(_nick,_pw, _name, _surname){}

QString User_Premium::getLabel() const{
   return "UserPremium";
}

bool User_Premium::ModifyUsers() const{
    return false;
}

bool User_Premium::ModifyProducts() const{
    return true;
}

bool User_Premium::premiumFunctions() const{
  return true;
}

