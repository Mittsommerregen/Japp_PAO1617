#ifndef PRODUCTSETTINGS
#define PRODUCTSETTINGS
#include<QDialog>
#include<QGridLayout>
#include<QGroupBox>
#include<QDateEdit>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QComboBox>
#include<QRadioButton>
#include<QCheckBox>

#include"../model/product_database.h"
#include "../model/user.h"
#include "../model/product.h"

class Productsettings:public QDialog{
    Q_OBJECT
private:
    User * user;
    Product * editedproduct;
    /* ********** Prodotto Generico ********** */
    QGroupBox * generalproduct;
    QLabel * labelName;
    QLabel * labelSviluppatore;
    QLabel * labelDataPubblicazione;
    QLineEdit * editName;
    QLineEdit * editSviluppatore;
    QDateEdit * editDataPubblicazione;
    /* ********** Scelta categoria e sottocategoria ********** */
    QLabel * labelProductType;
    QRadioButton * VB;
    QRadioButton * VL;
    QRadioButton * CoNG;
    QRadioButton * CoRC;
    /* ********** Videogame ********** */
    QGroupBox * Videogame;
    QLabel * labelPEGI;
    QLabel * labelPlatform;
    QLabel * labelGenre;
    QComboBox * editPEGI;
    QComboBox * editPlatform;
    QComboBox * editGenre;
    QCheckBox * editRemake;
    /* ********** Console ********** */
    QGroupBox * Console;
    QLabel * labelControllerTechType;
    QLabel * labelhardDisk;
    QLabel * labelmaxResolution;
    QLabel * labelconsoleColor;
    QComboBox * editControllerTechType;
    QComboBox * edithardDisk;
    QComboBox * editmaxResolution;
    QLineEdit * editconsoleColor;
    QCheckBox * editspecialEdition;
    /* **********  Videogame: Base ********** */
    QGroupBox * VGBase;
    QLabel * labelDim;
    QLineEdit * editDim;
    /* **********  Videogame: Limited ********** */
    QGroupBox * VGLimited;
    QLabel * labelextraContents;
    QLabel * labelartbookPages;
    QCheckBox * editSteelbook;
    QCheckBox * editDLC;
    QCheckBox * editActionFigure;
    QCheckBox * editsoundTrack;
    QLineEdit * editextraContents;
    QLineEdit * editartbookPages;
    /* ********** Console: NewGeneration ********** */
     QGroupBox* CNG;
     QCheckBox * editsupport4K;
    /* ********** Console: RetroConsole ********** */
    QGroupBox* CRC;
    QLabel * labelbit;
    QComboBox * editbit;

    QPushButton * pushSaveChanges;
    QPushButton * pushDelete;
    QPushButton * pushNew;
    QVBoxLayout * layoutProductSettings;
    QGridLayout * gridProduct;
public:
    Productsettings(User*, Product* prod=nullptr);
    void addLayout();
    void setNewLayout();
    void setModLayout();
    void setViewLayout(Product *);
    void hideVideogame();
    void hideVB();
    void hideVL();
    void hideConsole();
    void hideCoNG();
    void hideCoRC();
    void hideALL();
    void showSaveDeleteNew();

 public slots:
    /*************************
    *  Salva il prodotto     *
    **************************/
    void saveProduct();
    /***************************
    *  Elimina il prodotto     *
    ****************************/
    void saveDELETE();
    /*************************
    *  Salva nuovo     *
    *************************/
    void saveNEWPRODUCT();
    void closeWindow();

    void viewTypeVB(bool);
    void gridWidVB();
    void viewTypeVL(bool);
    void gridWidVL();
    void viewTypeCoNG(bool);
    void gridWidCoNG();
    void viewTypeCoRC(bool);
    void gridWidCoRC();

 signals:
    void sendDeleteProduct(Product *);
    void sendNewProduct(Product *);

    void sendInsertVB(Product*,User*,QString,QString,QString,QString,QString, QString, bool,QString);
    void sendInsertVL(Product*,User*,QString,QString,QString,QString,QString, QString, bool,bool,bool,bool,bool,QString,QString);
    void sendInsertCoNG(Product*,User*,QString,QString,QString,QString,QString,QString,QString,bool, bool);
    void sendInsertCoRC(Product*,User*,QString,QString,QString,QString,QString,QString,QString,bool, QString);


};
#endif // PRODUCTSETTINGS

