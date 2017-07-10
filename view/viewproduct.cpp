#include "viewproduct.h"
viewProduct::viewProduct(Product *prod): product(prod){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Visualizza Prodotto");
    addLayout();

}

void viewProduct::commonLabels(){
  labelName = new QLabel("Nome:");
  labelSviluppatore = new QLabel("Sviluppatore:");
  labelDataPubblicazione = new QLabel("Data Pubblicazione:");
  Name = new QLabel(product->getName());
  Sviluppatore = new QLabel(product->getDeveloper());
  DataPubblicazione = new QLabel(product->getDate().toString("yyyy.MM.dd"));
  labelProductType = new QLabel("Tipo:");
  ProductType = new QLabel(product->getTypeProd());
}

void viewProduct::commonLabelsVideogames(){
  labelPEGI = new QLabel("PEGI:");
  labelPlatform = new QLabel("Piattaforma:");
  labelGenre = new QLabel("Genere:");
  labelRemake = new QLabel("Remake:");
}

void viewProduct::commonLabelsConsoles(){
  labelControllerTechType = new QLabel("Tecnologia Controller:");
  labelhardDisk = new QLabel("Hard Disk:");
  labelmaxResolution = new QLabel("Massima Risoluzione:");
  labelconsoleColor = new QLabel("Colore Console:");
  labelspecialEdition = new QLabel("Edizione Speciale:");
}

void viewProduct::commonLayoutVideogames()const {
  gridProdLabel->addWidget(labelPEGI,4,0);
  gridProdLabel->addWidget(labelPlatform,5,0);
  gridProdLabel->addWidget(labelGenre,6,0);
  gridProdLabel->addWidget(labelRemake,7,0);

  gridProdLabel->addWidget(PEGI,4,1);
  gridProdLabel->addWidget(Platform,5,1);
  gridProdLabel->addWidget(Genre,6,1);
  gridProdLabel->addWidget(Remake,7,1);
}

void viewProduct::commonLayoutConsoles() const{
  gridProdLabel->addWidget(labelControllerTechType,4,0);
  gridProdLabel->addWidget(labelhardDisk,5,0);
  gridProdLabel->addWidget(labelmaxResolution,6,0);
  gridProdLabel->addWidget(labelconsoleColor,7,0);
  gridProdLabel->addWidget(labelspecialEdition,8,0);
  gridProdLabel->addWidget(ControllerTechType,4,1);
  gridProdLabel->addWidget(hardDisk,5,1);
  gridProdLabel->addWidget(maxResolution,6,1);
  gridProdLabel->addWidget(consoleColor,7,1);
  gridProdLabel->addWidget(specialEdition,8,1);
}
void viewProduct::addLayout(){
    commonLabels();
    if(product->getTypeProd() == "Videogame - Base"){
    commonLabelsVideogames();
    QString p = QString::number(dynamic_cast<Base*>(product)->getPegi());
    PEGI = new QLabel(p);
    Platform = new QLabel(dynamic_cast<Base*>(product)->getPlatform());
    Genre = new QLabel(dynamic_cast<Base*>(product)->getGenre());
    if(dynamic_cast<Base*>(product)->getRemake() == 1)
    Remake = new QLabel("Si");
    else Remake = new QLabel("No");
    labelDim = new QLabel("Dimensione (in GB):");
    Dim = new QLabel(QString::number(dynamic_cast<Base*>(product)->getDim()));
    }

    if(product->getTypeProd() == "Videogame - Limited"){
    commonLabelsVideogames();
    PEGI = new QLabel(QString::number(dynamic_cast<Limited*>(product)->getPegi()));

    Platform = new QLabel(dynamic_cast<Limited*>(product)->getPlatform());

    Genre = new QLabel(dynamic_cast<Limited*>(product)->getGenre());

    if(dynamic_cast<Limited*>(product)->getRemake() == 1)
    Remake = new QLabel("Si");
    else Remake = new QLabel("No");

    labelSteelbook = new QLabel("Steelbook:");
    if(dynamic_cast<Limited*>(product)->getSteelbook() == 1)
    Steelbook = new QLabel("Si");
    else Steelbook = new QLabel("No");

    labelDLC = new QLabel("DLC:");
    if(dynamic_cast<Limited*>(product)->getDlc() == 1)
    DLC = new QLabel("Si");
    else DLC = new QLabel("No");

    labelActionFigure = new QLabel("Action Figure:");
    if(dynamic_cast<Limited*>(product)->getActionfigure() == 1)
    actionFigure = new QLabel("Si");
    else actionFigure = new QLabel("No");

    labelsoundTrack = new QLabel("Soundtrack:");
    if(dynamic_cast<Limited*>(product)->getSoundtrack() == 1)
    soundTrack = new QLabel("Si");
    else soundTrack = new QLabel("No");

    labelextraContents = new QLabel("Contenuto Extra:");
    ExtraContents = new QLabel(dynamic_cast<Limited*>(product)->getExtracontents());
    labelartbookPages = new QLabel("Pagine Artbook:");
    ArtbookPages = new QLabel(QString::number(dynamic_cast<Limited*>(product)->getArtbookpages()));
    }

    if(product->getTypeProd() == "Console - Nuova Generazione"){
    commonLabelsConsoles();
    ControllerTechType = new QLabel(dynamic_cast<NewGeneration*>(product)->getControllerTechType());
    hardDisk = new QLabel(dynamic_cast<NewGeneration*>(product)->getHardDisk());
    maxResolution = new QLabel(dynamic_cast<NewGeneration*>(product)->getMaxResolution());
    consoleColor = new QLabel(dynamic_cast<NewGeneration*>(product)->getConsoleColor());
    if(dynamic_cast<NewGeneration*>(product)->getSpecialEdition() == 1)
    specialEdition = new QLabel("Si");
    else specialEdition = new QLabel("No");
    labelSupport4k = new QLabel("Supporto 4K:");
    if(dynamic_cast<NewGeneration*>(product)->getSupport4K() == 1)
    support4K = new QLabel("Si");
    else support4K = new QLabel("No");
    }

    if(product->getTypeProd() == "Console - Retro Console"){
    commonLabelsConsoles();
    ControllerTechType = new QLabel(dynamic_cast<RetroConsole*>(product)->getControllerTechType());
    hardDisk = new QLabel(dynamic_cast<RetroConsole*>(product)->getHardDisk());
    maxResolution = new QLabel(dynamic_cast<RetroConsole*>(product)->getMaxResolution());
    consoleColor = new QLabel(dynamic_cast<RetroConsole*>(product)->getConsoleColor());
    if(dynamic_cast<RetroConsole*>(product)->getSpecialEdition() == 1)
    specialEdition = new QLabel("Si");
    else specialEdition = new QLabel("No");
    labelbit = new QLabel("Bit:");
    bit = new QLabel(QString::number(dynamic_cast<RetroConsole*>(product)->getBit()));
}

    gridProdLabel=new QGridLayout;
    gridProdLabel->addWidget(labelName,0,0);
    gridProdLabel->addWidget(Name,0,1);
    gridProdLabel->addWidget(labelSviluppatore,1,0);
    gridProdLabel->addWidget(Sviluppatore,1,1);
    gridProdLabel->addWidget(labelDataPubblicazione,2,0);
    gridProdLabel->addWidget(DataPubblicazione,2,1);
    gridProdLabel->addWidget(labelProductType,3,0);
    gridProdLabel->addWidget(ProductType,3,1);

    if(product->getTypeProd() == "Videogame - Base"){
    commonLayoutVideogames();
    gridProdLabel->addWidget(labelDim, 8,0);
    gridProdLabel->addWidget(Dim,8,1);
    }
    if(product->getTypeProd() == "Videogame - Limited"){
    commonLayoutVideogames();
    gridProdLabel->addWidget(labelSteelbook,8,0);
    gridProdLabel->addWidget(labelDLC,9,0);
    gridProdLabel->addWidget(labelActionFigure,10,0);
    gridProdLabel->addWidget(labelsoundTrack,11,0);
    gridProdLabel->addWidget(labelextraContents,12,0);
    gridProdLabel->addWidget(labelartbookPages,13,0);
    gridProdLabel->addWidget(Steelbook,8,1);
    gridProdLabel->addWidget(DLC,9,1);
    gridProdLabel->addWidget(actionFigure,10,1);
    gridProdLabel->addWidget(soundTrack,11,1);
    gridProdLabel->addWidget(ExtraContents,12,1);
    gridProdLabel->addWidget(ArtbookPages,13,1);
    }

    if(product->getTypeProd() == "Console - Nuova Generazione"){
     commonLayoutConsoles();
      gridProdLabel->addWidget(labelSupport4k,9,0);
      gridProdLabel->addWidget(support4K,9,1);
    }
   if(product->getTypeProd() == "Console - Retro Console"){
     commonLayoutConsoles();
     gridProdLabel->addWidget(labelbit,9,0);
     gridProdLabel->addWidget(bit,9,1);
   }


    window = new QWidget(this);
    window->setLayout(gridProdLabel);
    window->show();
}
