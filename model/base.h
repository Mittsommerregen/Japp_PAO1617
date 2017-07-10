#ifndef BASE
#define BASE
#include "videogame.h"
//#include<QXmlStreamWriter>
//#include<QXmlStreamReader>

class Base: public Videogame {
private:
    double dim;

public:
  Base(const QString& Name="", const QString& Developer="", const QDate& Pubb_date = QDate::currentDate(),
       unsigned short int Pegi=0, const QString& Platform="", const QString& Genre="", bool Remake=false,
       double Dim=0);

   // virtual ~Base();
  virtual void saveProduct(QXmlStreamWriter & w);
  virtual void loadProduct(QXmlStreamReader & r);

  //Implemento il metodo virtuale puro che restituisce la tipologia di appartenenza di un oggetto del negozio
  virtual QString getTypeProd() const;

  double getDim() const;
  void setDim(double d);


};

#endif // BASE

