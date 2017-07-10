#ifndef USER_ADMIN
#define USER_ADMIN
#include "user.h"
#include "product.h"
#include "user_database.h"
#include "product_database.h"

class User_Admin: public User{
public:
    User_Admin(const QString& _nick="", const QString& _pw="", const QString& _name="", const QString& _surname="");

    QString getLabel() const;
    virtual bool ModifyUsers() const;
    virtual bool ModifyProducts() const;
    virtual bool premiumFunctions() const;

};
#endif // USER_ADMIN

