#include "base.h"

Base::Base(const QString& Name, const QString& Developer, const QDate& Pubb_date,
unsigned short Pegi, const QString& Platform, const QString& Genre, bool Remake, double Dim):
Videogame(Name, Developer, Pubb_date, Pegi, Platform, Genre, Remake), dim(Dim){}

//Base::~Base(){}

void Base::saveProduct(QXmlStreamWriter & w){
    w.writeStartElement("Videogame-Base");
    saveCommonFieldsProduct(w);
    w.writeTextElement("PEGI", QString::number(getPegi()));
    w.writeTextElement("Piattaforma", getPlatform());
    w.writeTextElement("Genere", getGenre());
    w.writeTextElement("Remake", getRemake() ? "1" : "0");
    w.writeTextElement("Dimensione",QString::number(getDim()));
    w.writeEndElement();
}



void Base::loadProduct(QXmlStreamReader &r){
    loadCommonFieldsProduct(r);
    if(r.name() == "PEGI"){
        setPegi((r.readElementText()).toInt());
        r.readNextStartElement();
    }
    if(r.name() == "Piattaforma"){
        setPlatform(r.readElementText());
        r.readNextStartElement();
    }
    if(r.name() == "Genere"){
        setGenre(r.readElementText());
        r.readNextStartElement();
    }
    if(r.name() == "Remake"){
        setRemake((r.readElementText() == "1")? true : false);
        r.readNextStartElement();
    }
    if(r.name() == "Dimensione"){
        setDim((r.readElementText()).toDouble());
        r.readNextStartElement();
    }
}



QString Base::getTypeProd() const{
    return "Videogame - Base";
}

double Base::getDim() const{
    return dim;
}

void Base::setDim(double d){
    dim=d;
}


