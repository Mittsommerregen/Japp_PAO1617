/*
 * Classe dedicata all'utente base.
*/
#ifndef USER_BASE
#define USER_BASE
#include "user.h"
#include "product.h"
#include "product_database.h"

class User_Base: public User{
 public:
   User_Base(const QString& _nick="", const QString& _pw="", const QString& _name="", const QString& _surname="");
   QString getLabel() const;
   virtual bool ModifyUsers() const;
   virtual bool ModifyProducts() const;
   virtual bool premiumFunctions() const;

};

#endif // USER_BASE

