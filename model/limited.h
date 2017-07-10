/*
 * La classe Limited descrive una particolare versione di un Videogame.
 * Una limited, essendo un'edizione limitata, ha dei contenuti speciali oltre al gioco base.
 * Il campo dati Steelbook indica se la copertina è in versione standard o in versione steelbook.
 * Il campo dati DLC indica se ci sono contenuti scaricabili aggiuntivi in bundle.
 * Il campo dati ActionFigure indica se nel pacchetto è incluso un modellino.
 * Il campo dati Soundtrack indica se nel pacchetto è inclusa una colonna sonora.
 * Il campo dati ExtraContents indica se in bundle ci sono altri contenuti oltre a quelli già citati in precedenza.
 * Il campo dati Artbookpages indica il numero di pagine dell'Artbook del videogioco.
 *
 */

#ifndef LIMITED
#define LIMITED
#include "videogame.h"

class Limited: public Videogame {
private:
    bool steelbook;
    bool DLC;
    bool actionFigure;
    bool soundTrack;
    QString extraContents;
    unsigned int artbookPages;
public:
    Limited(const QString& Name="", const QString& Developer="",const QDate& Pubb_date = QDate::currentDate(),
    unsigned short int Pegi=0, const QString& Platform="", const QString& Genre="", bool Remake=false,
    bool Steelbook=false, bool Dlc=false, bool Actionfigure=false, bool Soundtrack=false, const QString& Extracontents="",
    unsigned int Artbookpages=0);
    //virtual ~Limited();

    virtual void saveProduct(QXmlStreamWriter & w);
    virtual void loadProduct(QXmlStreamReader & r);

    //Implemento il metodo virtuale puro che restituisce la tipologia di appartenenza di un oggetto del negozio
    virtual QString getTypeProd() const;

    //metodi get/set
    bool getSteelbook() const;
    void setSteelbook(bool);
    bool getDlc() const;
    void setDlc(bool);
    bool getActionfigure() const;
    void setActionfigure(bool);
    bool getSoundtrack() const;
    void setSoundtrack(bool);
    QString getExtracontents() const;
    void setExtracontents(QString);
    unsigned int getArtbookpages() const;
    void setArtbookpages(unsigned int);

};

#endif // LIMITED


