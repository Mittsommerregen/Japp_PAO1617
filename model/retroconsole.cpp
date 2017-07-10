#include "retroconsole.h"
#include <typeinfo>

RetroConsole::RetroConsole(const QString& Name, const QString& Developer, const QDate& Pubb_date,
const QString& Controllertechtype, const QString &HardDisk, const QString& Maxresolution, const QString& Consolecolor, bool Specialedition, unsigned int Bit):
Console(Name, Developer, Pubb_date, Controllertechtype, HardDisk, Maxresolution, Consolecolor, Specialedition), bit(Bit) {}

//RetroConsole::~RetroConsole(){}

void RetroConsole::loadProduct(QXmlStreamReader &r){
     loadCommonFieldsProduct(r);
     if(r.name() == "TecnologiaController"){
         setControllerTechType(r.readElementText());
         r.readNextStartElement();
     }
     if(r.name() == "HardDisk"){
         setHardDisk((r.readElementText()));
         r.readNextStartElement();
     }
     if(r.name() == "RisoluzioneMassima"){
         setMaxResolution(r.readElementText());
         r.readNextStartElement();
     }
     if(r.name() == "ColoreConsole"){
         setConsoleColor(r.readElementText());
         r.readNextStartElement();
     }
     if(r.name() == "EdizioneSpeciale"){
         setSpecialEdition((r.readElementText() =="1")? true:false);
         r.readNextStartElement();
     }
     if(r.name() == "Bit"){
         setBit((r.readElementText()).toInt());
         r.readNextStartElement();
     }
}

void RetroConsole::saveProduct(QXmlStreamWriter &w){
    w.writeStartElement("Console-RetroConsole");
    saveCommonFieldsProduct(w);
    w.writeTextElement("TecnologiaController", getControllerTechType());
    w.writeTextElement("HardDisk", getHardDisk());
    w.writeTextElement("RisoluzioneMassima", getMaxResolution());
    w.writeTextElement("ColoreConsole",getConsoleColor());
    w.writeTextElement("EdizioneSpeciale",getSpecialEdition() ? "1" : "0");
    w.writeTextElement("Bit",QString::number(getBit()));
     w.writeEndElement();
}



QString RetroConsole::getTypeProd() const {
    return "Console - Retro Console";
}

unsigned int RetroConsole::getBit() const{
    return bit;
}

void RetroConsole::setBit(unsigned int bi){
    bit=bi;
}
