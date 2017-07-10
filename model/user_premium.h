/*
 * Classe dedicata all'utente Premium.
*/
#ifndef USER_PREMIUM
#define USER_PREMIUM
#include "user_base.h"

class User_Premium: public User_Base{
public:
    User_Premium(const QString& _nick="", const QString& _pw="", const QString& _name="", const QString& _surname="");
    virtual QString getLabel() const;
    virtual bool ModifyUsers() const;
    virtual bool ModifyProducts() const;
    virtual bool premiumFunctions() const;
};
#endif // USER_PREMIUM

