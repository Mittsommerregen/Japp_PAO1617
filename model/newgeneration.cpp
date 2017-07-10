#include "newgeneration.h"


NewGeneration::NewGeneration(const QString& Name, const QString& Developer, const QDate& Pubb_date, const QString& Controllertechtype, const QString &HardDisk, const QString& Maxresolution,
const QString& Consolecolor, bool Specialedition, bool S4k):
Console(Name, Developer, Pubb_date, Controllertechtype, HardDisk, Maxresolution, Consolecolor, Specialedition), support4K(S4k){}

//NewGeneration::~NewGeneration(){}

void NewGeneration::loadProduct(QXmlStreamReader &r){
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
    if(r.name() == "Supporto4k"){
        setSupport4K((r.readElementText() =="1")? true:false);
        r.readNextStartElement();
    }
}

void NewGeneration::saveProduct(QXmlStreamWriter &w){
    w.writeStartElement("Console-NewGeneration");
    saveCommonFieldsProduct(w);
    w.writeTextElement("TecnologiaController", getControllerTechType());
    w.writeTextElement("HardDisk", getHardDisk());
    w.writeTextElement("RisoluzioneMassima", getMaxResolution());
    w.writeTextElement("ColoreConsole",getConsoleColor());
    w.writeTextElement("EdizioneSpeciale",getSpecialEdition() ? "1" : "0");
    w.writeTextElement("Supporto4k", getSupport4K() ? "1" : "0");
    w.writeEndElement();
}


QString NewGeneration::getTypeProd() const{
    return "Console - Nuova Generazione";
}

bool NewGeneration::getSupport4K() const{
    return support4K;
}

void NewGeneration::setSupport4K(bool s4k){
    support4K=s4k;
}
