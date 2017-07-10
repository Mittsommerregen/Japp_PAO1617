#ifndef USER
#define USER
#include<QString>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include "product.h"
#include "product_database.h"

class User{
private:
    QString nickname;
    QString password;
    QString name;
    QString surname;
public:
    User(const QString& _nick="", const QString& _pw="", const QString& _name="", const QString& _surname="");
    virtual ~User()=default;
    virtual QString getLabel() const = 0;
    virtual bool ModifyUsers() const =0;
    virtual bool ModifyProducts() const =0;
    virtual bool premiumFunctions() const =0;
    void setNickname(const QString&);
    void setPassword(const QString&);
    void setName(const QString&);
    void setSurname(const QString&);
    QString getNickname() const;
    QString getPassword() const;
    QString getName()const;
    QString getSurname()const;

    void saveCommonFieldsUser(QXmlStreamWriter& xmlWriter);
    void loadCommonFieldsUser(QXmlStreamReader& xmlReader);

    virtual void saveUser(QXmlStreamWriter& xmlWriter);
    virtual void loadUser(QXmlStreamReader& xmlReader);
};
#endif // USER

