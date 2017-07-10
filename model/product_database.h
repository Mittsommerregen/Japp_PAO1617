#ifndef PRODUCT_DATABASE
#define PRODUCT_DATABASE
#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QList>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<iostream>
#include"product.h"
#include"base.h"
#include "limited.h"
#include "newgeneration.h"
#include "retroconsole.h"

class productDatabase{
private:
    static QString filename;
    QList<Product*> products;
public:
    productDatabase();
    ~productDatabase();

    //bool isEmpty() const;

    //Metodo che permette di aggiungere un prodotto nel DB
    void addProductToDB(Product*);

    //Metodo che permette di rimuovere un prodotto dal DB
    void removeProductFromDB(Product*);

    //Metodo utile per ottenere un prodotto dato il serial number (Usato nella view per la modifica di un dato prodotto)
    Product* getProduct(int serialnumber)const;

    //Metodo che restituisce la lista di puntatori ai prodotti presenti in DB
    const QList<Product*> getAllProducts()const;

    //Data una o n lettere restituisce una lista di puntatori a quei prodotti che hanno una corrispondenza con tali lettere,
    //altrimenti restituisce una lista vuota
    const QList<Product*> productContainsWord(const QString &) const;

    /******   METODI PER LE INTERROGAZIONI NEL DB PER UTENTE PREMIUM ******/
    QList<Product*> videogameRemake() const;
    QList<Product*> videogameWithThisPEGI(int) const;
    QList<Product*> limitedVideogamewithExtraContents() const;
    QList<Product*> consoleSpecialEdition() const;

    //Metodi di caricamento e salvataggio nel database
    void Load();
    void SaveAndClose();
};

#endif // PRODUCT_DATABASE

