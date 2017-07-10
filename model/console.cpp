#include "console.h"

//COSTRUTTORE DI DEFAULT
Console::Console(const QString& Name, const QString& Developer, const QDate& Pubb_date,
const QString& Controllertechtype, const QString& HardDisk, const QString& Maxresolution, const QString& Consolecolor, bool Specialedition) :
    Product(Name, Developer, Pubb_date), controllerTechType(Controllertechtype),hardDisk(HardDisk),
    maxResolution(Maxresolution), consoleColor(Consolecolor), specialEdition(Specialedition) {}


//DISTRUTTORE VIRTUALE
//Console::~Console() {}


//GETTER E SETTER
QString Console::getControllerTechType() const{
    return controllerTechType;
}
void Console::setControllerTechType(QString Ctt){
    controllerTechType = Ctt;
}
QString Console::getHardDisk() const{
    return hardDisk;
}
void Console::setHardDisk(QString hd){
    hardDisk = hd;
}
QString Console::getMaxResolution() const{
    return maxResolution;
}
void Console::setMaxResolution(QString mr){
    maxResolution = mr;
}
QString Console::getConsoleColor() const{
    return consoleColor;
}
void Console::setConsoleColor(QString Cc){
    consoleColor = Cc;
}
bool Console::getSpecialEdition() const{
    return specialEdition;
}
void Console::setSpecialEdition(bool se){
    specialEdition = se;
}


