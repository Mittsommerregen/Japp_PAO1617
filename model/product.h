/*
 * La classe Product rappresenta un generico prodotto all'interno del database, ed è caratterizzato dalle seguenti informazioni:
 * numero seriale univoco per ogni prodotto, nome del prodotto, casa sviluppatrice, data di inserimento nel database.
 */

#ifndef PRODUCT
#define PRODUCT
#include<QString>
#include<QDate>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>

class Product{
private:
    static int serialnumber;
    int currentSerialNumber;
    QString name;
    QString developer;
    QDate pubb_date;
public:
    Product(const QString& Name="", const QString& Developer="",const QDate& Pubb_date = QDate::currentDate());
    virtual ~Product()=default;

    // METODI VIRTUALI PURI
    //Restituisce la tipologia di appartenenza di un oggetto del negozio
    virtual QString getTypeProd() const=0;
    virtual void saveProduct(QXmlStreamWriter &)=0;
    virtual void loadProduct(QXmlStreamReader &)=0;

    //METODI GETTER E SETTER
    int getSerialNumber()const;
    QString getName()const;
    QString getDeveloper()const;
    QDate getDate()const;
    void setName(const QString&);
    void setDeveloper(const QString&);
    void setDate(const QDate&);

    void saveCommonFieldsProduct(QXmlStreamWriter& xmlWriter);
    void loadCommonFieldsProduct(QXmlStreamReader& xmlReader);


 };
#endif // PRODUCT

