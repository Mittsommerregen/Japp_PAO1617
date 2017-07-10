#include "limited.h"

Limited::Limited(const QString& Name, const QString& Developer, const QDate& Pubb_date, unsigned short Pegi, const QString& Platform,
const QString& Genre, bool Remake, bool Steelbook, bool Dlc, bool Actionfigure, bool Soundtrack, const QString& Extracontents,
unsigned int Artbookpages): Videogame(Name, Developer, Pubb_date, Pegi, Platform, Genre, Remake),
steelbook(Steelbook), DLC(Dlc), actionFigure(Actionfigure), soundTrack(Soundtrack), extraContents(Extracontents),
artbookPages(Artbookpages){}

//Limited::~Limited(){}

void Limited::loadProduct(QXmlStreamReader &r){
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
   if(r.name() == "Steelbook"){
       setSteelbook((r.readElementText() == "1")? true:false);
       r.readNextStartElement();
   }
   if(r.name() == "DLC"){
       setDlc((r.readElementText() == "1")? true:false);
       r.readNextStartElement();
   }
   if(r.name() == "ActionFigure"){
       setActionfigure((r.readElementText() == "1")? true:false);
       r.readNextStartElement();
   }
   if(r.name() == "SoundTrack"){
       setSoundtrack((r.readElementText()  == "1")? true:false);
       r.readNextStartElement();
   }
   if(r.name() == "ExtraContents"){
       setExtracontents(r.readElementText());
       r.readNextStartElement();
   }
   if(r.name() == "ArtbookPages"){
       setArtbookpages((r.readElementText()).toInt());
       r.readNextStartElement();
   }
}

void Limited::saveProduct(QXmlStreamWriter &w){
    w.writeStartElement("Videogame-Limited");
    saveCommonFieldsProduct(w);
    w.writeTextElement("PEGI", QString::number(getPegi()));
    w.writeTextElement("Piattaforma", getPlatform());
    w.writeTextElement("Genere", getGenre());
    w.writeTextElement("Remake", getRemake() ? "1" : "0");
    w.writeTextElement("Steelbook", getSteelbook() ? "1" : "0");
    w.writeTextElement("DLC", getDlc() ? "1" : "0");
    w.writeTextElement("ActionFigure", getActionfigure() ? "1" : "0");
    w.writeTextElement("SoundTrack", getSoundtrack() ? "1" : "0");
    w.writeTextElement("ExtraContents", getExtracontents());
    w.writeTextElement("ArtbookPages", QString::number(getArtbookpages()));
    w.writeEndElement();
}


QString Limited::getTypeProd() const{
    return "Videogame - Limited";
}


bool Limited::getSteelbook() const{
    return steelbook;
}

void Limited::setSteelbook(bool s){
    steelbook=s;
}

bool Limited::getDlc() const{
    return DLC;
}
void Limited::setDlc(bool d){
    DLC=d;
}

bool Limited::getActionfigure() const{
    return actionFigure;
}
void Limited::setActionfigure(bool a){
    actionFigure=a;
}

bool Limited::getSoundtrack() const{
    return soundTrack;
}
void Limited::setSoundtrack(bool so){
    soundTrack=so;
}

QString Limited::getExtracontents() const{
    return extraContents;
}
void Limited::setExtracontents(QString ex){
    extraContents=ex;
}

unsigned int Limited::getArtbookpages() const{
    return artbookPages;
}
void Limited::setArtbookpages(unsigned int art){
    artbookPages=art;
}
