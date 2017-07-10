#ifndef NEWGENERATION
#define NEWGENERATION
#include "console.h"

class NewGeneration:public Console{
private:
    bool support4K;

public:
    NewGeneration(const QString& Name="", const QString& Developer="", const QDate& Pubb_date = QDate::currentDate(),
    const QString& Controllertechtype="", const QString& HardDisk = "", const QString& Maxresolution="",
    const QString& Consolecolor="", bool Specialedition=false, bool S4k=false);
    //virtual ~NewGeneration();

    void saveProduct(QXmlStreamWriter & w);
    void loadProduct(QXmlStreamReader & r);

    //Implemento il metodo virtuale puro che restituisce la tipologia di appartenenza di un oggetto del negozio
    virtual QString getTypeProd() const;
    bool getSupport4K() const;
    void setSupport4K(bool);

};

#endif // NEWGENERATION

