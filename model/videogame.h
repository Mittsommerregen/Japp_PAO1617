/*
 * La classe Videogame deriva dalla classe base astratta Product e rappresenta un generico videogame
 * presente in database. Troviamo come campi dati il PEGI (Pan European Game Information), ovvero il sistema
 * di classificazione in base all'età del giocatore, Platform, ovvero la piattaforma console sulla quale far girare un gioco
 * (NOTA: Nello store può essere presente il medesimo videogioco ma in diverse versioni di console), e Genre, ovvero il genere
 * di appartenenza del videogioco, utile per la catalogazione, e Remake, per segnalare se un videogioco è un adattamento di un titolo
 * uscito precedentemente con l'intento di modernizzare il gioco per un nuovo hardware (esempio: Pokémon Rosso/Blu per Game Boy e
 * Pokemon Rosso Fuoco/Verde Foglia per Game Boy Advance).
 */
#ifndef VIDEOGAME
#define VIDEOGAME
#include "product.h"

//CLASSE ASTRATTA
class Videogame : public Product{
private:
    unsigned short int PEGI;
    QString platform;
    QString genre;
    bool remake;
public:
    Videogame(const QString& Name="", const QString& Developer="", const QDate& Pubb_date = QDate::currentDate(),
    unsigned short int Pegi=0, const QString& Platform="", const QString& Genre="", bool Remake=false );
    //virtual ~Videogame();
    unsigned short int getPegi() const;
    QString getPlatform() const;
    QString getGenre() const;
    bool getRemake() const;
    void setPegi(unsigned short int);
    void setPlatform(QString);
    void setGenre(QString);
    void setRemake(bool);
};

#endif // VIDEOGAME

