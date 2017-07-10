#include "videogame.h"

//COSTRUTTORE DI DEFAULT
Videogame::Videogame(const QString& Name, const QString& Developer, const QDate& Pubb_date,
unsigned short int Pegi, const QString& Platform, const QString& Genre, bool Remake):
Product(Name, Developer, Pubb_date), PEGI(Pegi), platform(Platform), genre(Genre), remake(Remake) {}

//DISTRUTTORE VIRTUALE
//Videogame::~Videogame() {}

unsigned short int Videogame::getPegi() const{
    return PEGI;
}

void Videogame::setPegi(unsigned short p) {
    PEGI=p;
}

QString Videogame::getPlatform() const {
    return platform;
}

void Videogame::setPlatform(QString platf) {
    platform=platf;
}

QString Videogame::getGenre() const {
    return genre;
}

void Videogame::setGenre(QString g) {
    genre=g;
}
bool Videogame::getRemake() const{
    return remake;
}
void Videogame::setRemake(bool re){
    remake=re;
}


