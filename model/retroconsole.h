#ifndef RETROCONSOLE
#define RETROCONSOLE
#include "console.h"

class RetroConsole: public Console{
private:
    unsigned int bit;
public:
    RetroConsole(const QString& Name="", const QString& Developer="", const QDate& Pubb_date = QDate::currentDate(),
    const QString& Controllertechtype="", const QString& HardDisk = "", const QString& Maxresolution="", const QString& Consolecolor="", bool Specialedition=false,
    unsigned int Bit=0);
   // virtual ~RetroConsole();

    void saveProduct(QXmlStreamWriter & w);
    void loadProduct(QXmlStreamReader & r);

    //Implemento il metodo virtuale puro che restituisce la tipologia di appartenenza di un oggetto del negozio
    virtual QString getTypeProd() const;

    unsigned int getBit() const;
    void setBit(unsigned int);
};

#endif // RETROCONSOLE

