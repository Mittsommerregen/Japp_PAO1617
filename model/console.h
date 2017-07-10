/*
 * La classe Console identifica una generica console presente nel database.
 * Tra i campi dati troviamo ControllerTechType che indentifica la tipologia della tecnologia usata dal controller
 * (se cablato o wireless). Troviamo anche HardDisk che esprime la capacità del disco.
 * MaxResolution identifica la massima risoluzione video ottenibile, ConsoleColor invece rappresenta la colorazione
 * della scocca della console.
 * Inoltre SpecialEdition è un booleano che indica se la console è una versione speciale (tiratura limitata).
 *
 */

#ifndef CONSOLE
#define CONSOLE
#include "product.h"

//CLASSE ASTRATTA
class Console: public Product{
 private:
    QString controllerTechType;
    QString hardDisk;
    QString maxResolution;
    QString consoleColor;
    bool specialEdition;
public:
    Console(const QString& Name="", const QString& Developer="", const QDate& Pubb_date = QDate::currentDate(),
    const QString& Controllertechtype="", const QString& HardDisk= "", const QString& Maxresolution="",
    const QString& Consolecolor="", bool Specialedition=false);
    // virtual ~Console();

     QString getControllerTechType() const;
     void setControllerTechType(QString);
     QString getHardDisk() const;
     void setHardDisk(QString);
     QString getMaxResolution() const;
     void setMaxResolution(QString);
     QString getConsoleColor() const;
     void setConsoleColor(QString);
     bool getSpecialEdition() const;
     void setSpecialEdition(bool);

};

#endif // CONSOLE

