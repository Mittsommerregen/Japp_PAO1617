#ifndef VIEWPRODUCT
#define VIEWPRODUCT
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include "../model/product.h"
#include "../model/base.h"
#include "../model/limited.h"
#include "../model/newgeneration.h"
#include "../model/retroconsole.h"

class viewProduct: public QDialog{
private:
     Q_OBJECT
    Product * product;
    /* ********** Prodotto Generico ********** */
    QLabel * labelName;
    QLabel * labelSviluppatore;
    QLabel * labelDataPubblicazione;
    QLabel * Name;
    QLabel * Sviluppatore;
    QLabel * DataPubblicazione;
    /* ********** Scelta categoria e sottocategoria ********** */
    QLabel * labelProductType;
    QLabel * ProductType;
    /* ********** Videogame ********** */
    QLabel * labelPEGI;
    QLabel * labelPlatform;
    QLabel * labelGenre;
    QLabel * labelRemake;
    QLabel * PEGI;
    QLabel * Platform;
    QLabel * Genre;
    QLabel * Remake;
    /* ********** Console ********** */
    QLabel * labelControllerTechType;
    QLabel * labelhardDisk;
    QLabel * labelmaxResolution;
    QLabel * labelconsoleColor;
    QLabel * labelspecialEdition;
    QLabel * ControllerTechType;
    QLabel * hardDisk;
    QLabel * maxResolution;
    QLabel * consoleColor;
    QLabel * specialEdition;
    /* **********  Videogame: Base ********** */
    QLabel * labelDim;
    QLabel * Dim;
    /* **********  Videogame: Limited ********** */
    QLabel * labelSteelbook;
    QLabel * Steelbook;
    QLabel * labelDLC;
    QLabel * DLC;
    QLabel * labelActionFigure;
    QLabel * actionFigure;
    QLabel * labelsoundTrack;
    QLabel * soundTrack;
    QLabel * ExtraContents;
    QLabel * ArtbookPages;
    QLabel * labelextraContents;
    QLabel * labelartbookPages;
    /* ********** Console: NewGeneration ********** */
    QLabel * labelSupport4k;
    QLabel * support4K;
    /* ********** Console: RetroConsole ********** */
    QLabel * labelbit;
    QLabel * bit;

    QHBoxLayout * layoutProductView;
    QGridLayout * gridProdLabel;
    QWidget * window;
public:
    viewProduct(Product* prod=nullptr);
    void addLayout();
    void commonLabels();
    void commonLabelsVideogames();
    void commonLabelsConsoles();
    void commonLayoutVideogames() const;
    void commonLayoutConsoles() const;
};

#endif // VIEWPRODUCT

