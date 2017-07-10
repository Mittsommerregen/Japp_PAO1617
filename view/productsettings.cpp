#include "productsettings.h"
Productsettings::Productsettings(User *u, Product *prod): user(u), editedproduct(prod){
  this->setAttribute(Qt::WA_DeleteOnClose);
  setWindowTitle("Gestione Prodotto");
  addLayout();
  move(500,150);
}

void Productsettings::addLayout(){
  /*  CAMPI COMUNI PER OGNI PRODOTTO */
  labelName=new QLabel("Nome");
  labelSviluppatore=new QLabel("Sviluppatore");
  labelDataPubblicazione=new QLabel("Data Pubblicazione");

  editName=new QLineEdit();
  editName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
  editName->setPlaceholderText("Inserisci nome");

  editSviluppatore=new QLineEdit();
  editSviluppatore->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
  editSviluppatore->setPlaceholderText("Inserisci sviluppatore");

  editDataPubblicazione= new QDateEdit(QDate::currentDate());
  editDataPubblicazione->setDisplayFormat("yyyy.MM.dd");


  /*SCELTA CATEGORIA E SOTTOCATEGORIA*/
  labelProductType = new QLabel("Tipologia prodotto:");

  VB = new QRadioButton("Videogioco Base", this);
  VL = new QRadioButton("Videogioco Limited", this);
  CoNG = new QRadioButton("Console Nuova Generazione", this);
  CoRC = new QRadioButton("Console Retro Console", this);


  /* VIDEOGIOCO GENERICO */
  labelPEGI = new QLabel("PEGI");
  labelPlatform = new QLabel("Piattaforma");
  labelGenre = new QLabel("Genere");

  editPEGI = new QComboBox();
  editPEGI->addItem("3");
  editPEGI->addItem("7");
  editPEGI->addItem("12");
  editPEGI->addItem("16");
  editPEGI->addItem("18");

  editPlatform = new QComboBox();
  editPlatform->addItem("Sega Mega Drive");
  editPlatform->addItem("Nintendo Game Boy");
  editPlatform->addItem("Nintendo Entertainment System");
  editPlatform->addItem("PlayStation");
  editPlatform->addItem("PlayStation 2");
  editPlatform->addItem("PlayStation 3");
  editPlatform->addItem("PlayStation 4");
  editPlatform->addItem("Wii");
  editPlatform->addItem("Wii U");
  editPlatform->addItem("Nintendo Switch");
  editPlatform->addItem("Xbox");
  editPlatform->addItem("Xbox 360");
  editPlatform->addItem("Xbox One");

  editGenre = new QComboBox();
  editGenre->addItem("Arcade");
  editGenre->addItem("Action");
  editGenre->addItem("RPG");
  editGenre->addItem("MMORPG");
  editGenre->addItem("Party Game");
  editGenre->addItem("Picchiaduro");
  editGenre->addItem("Platform");
  editGenre->addItem("Simulazione");
  editGenre->addItem("Sparatutto");

  editRemake=new QCheckBox(tr("Remake"));

   /*VIDEOGIOCO BASE*/
   labelDim = new QLabel("Dimensione");
   editDim= new QLineEdit();
   editDim->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}")));
   editDim->setPlaceholderText("Inserisci dimensione (GB)");

    /* VIDEOGIOCO LIMITED */
   editSteelbook = new QCheckBox(tr("Steelbook"));
   editDLC = new QCheckBox(tr("DLC"));
   editActionFigure = new QCheckBox(tr("Action Figure"));
   editsoundTrack = new QCheckBox(tr("Soundtrack"));
   labelextraContents = new QLabel("Contenuti Extra");
   editextraContents = new QLineEdit();
   editextraContents->setValidator(new QRegExpValidator(QRegExp("[A-Za-z\\s]{1,15}")));
   editextraContents->setPlaceholderText("Digita 'nessuno' se inesistente");
   labelartbookPages = new QLabel("Numero pagine artbook");
   editartbookPages = new QLineEdit();
   editartbookPages->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));;
   editartbookPages->setPlaceholderText("Inserisci numero delle pagine dell'Artbook");

  /* CONSOLE GENERICA */
  labelControllerTechType= new QLabel("Tecnologia Controller");
  labelhardDisk = new QLabel("Hard Disk");
  labelmaxResolution = new QLabel("Risoluzione Massima");
  labelconsoleColor = new QLabel("Colore Console");

  editControllerTechType = new QComboBox();
  editControllerTechType->addItem("Wired");
  editControllerTechType->addItem("Wireless");

  edithardDisk = new QComboBox();
  edithardDisk->addItem("Inferiore a 100 GB");
  edithardDisk->addItem("100 GB");
  edithardDisk->addItem("250 GB");
  edithardDisk->addItem("500 GB");
  edithardDisk->addItem("1 TB");
  edithardDisk->addItem("Superiore a 1 TB");

  editmaxResolution = new QComboBox();
  editmaxResolution->addItem("240p/QVGA");
  editmaxResolution->addItem("360p");
  editmaxResolution->addItem("480p");
  editmaxResolution->addItem("576p");
  editmaxResolution->addItem("720p");
  editmaxResolution->addItem("1080p");

  editconsoleColor = new QLineEdit();
  editconsoleColor->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,15}")));
  editconsoleColor->setPlaceholderText("Inserisci colore");

  editspecialEdition = new QCheckBox(tr("Edizione Speciale"));

  /* CONSOLE NEWGEN */
  editsupport4K = new QCheckBox(tr("Supporto 4K"));

  /* CONSOLE RETROCONSOLE */
  labelbit = new QLabel("Bit");
  editbit = new QComboBox();
  editbit->addItem("8");
  editbit->addItem("16");
  editbit->addItem("32");

  pushSaveChanges=new QPushButton("Salva le modifiche");
  pushDelete=new QPushButton("Elimina il prodotto");
  pushNew=new QPushButton("Crea nuovo prodotto");

  gridProduct=new QGridLayout;
  gridProduct->addWidget(labelName);
  gridProduct->addWidget(editName);
  gridProduct->addWidget(labelSviluppatore);
  gridProduct->addWidget(editSviluppatore);
  gridProduct->addWidget(labelDataPubblicazione);
  gridProduct->addWidget(editDataPubblicazione);
  gridProduct->addWidget(labelProductType);
  gridProduct->addWidget(VB);
  gridProduct->addWidget(VL);
  gridProduct->addWidget(CoNG);
  gridProduct->addWidget(CoRC);

  layoutProductSettings=new QVBoxLayout();
  layoutProductSettings->addLayout(gridProduct);

  connect(VB,SIGNAL(toggled(bool)),this,SLOT(viewTypeVB(bool)));
  connect(VL, SIGNAL(toggled(bool)),this,SLOT(viewTypeVL(bool)));
  connect(CoNG,SIGNAL(toggled(bool)),this,SLOT(viewTypeCoNG(bool)));
  connect(CoRC,SIGNAL(toggled(bool)),this,SLOT(viewTypeCoRC(bool)));

  connect(pushSaveChanges,SIGNAL(clicked()),this,SLOT(saveProduct()));
  connect(pushDelete,SIGNAL(clicked()),this,SLOT(saveDELETE()));
  connect(pushNew,SIGNAL(clicked(bool)),this,SLOT(saveNEWPRODUCT()));
  setLayout(layoutProductSettings);
  }

  void Productsettings::showSaveDeleteNew(){
  gridProduct->addWidget(pushSaveChanges);
  gridProduct->addWidget(pushDelete);
  gridProduct->addWidget(pushNew);
  }


void Productsettings::gridWidVB(){
  gridProduct->addWidget(labelPEGI);
  gridProduct->addWidget(editPEGI);
  gridProduct->addWidget(labelPlatform);
  gridProduct->addWidget(editPlatform);
  gridProduct->addWidget(labelGenre);
  gridProduct->addWidget(editGenre);
  gridProduct->addWidget(editRemake);

  gridProduct->addWidget(labelDim);
  gridProduct->addWidget(editDim);
  showSaveDeleteNew();
}


void Productsettings::hideVideogame(){
  labelPEGI->hide(); editPEGI->hide();
  labelGenre->hide(); editGenre->hide();
  labelPlatform->hide(); editPlatform->hide();
  editRemake->hide();
}

void Productsettings::hideVB(){
  labelDim->hide(); editDim->hide();

}

void Productsettings::hideVL(){
  editSteelbook->hide();
  editDLC->hide();
  editActionFigure->hide();
  editsoundTrack->hide();
  labelextraContents->hide();
  editextraContents->hide();
  labelartbookPages->hide();
  editartbookPages->hide();
}

void Productsettings::hideConsole(){
  labelControllerTechType->hide();
  editControllerTechType->hide();
  labelhardDisk->hide();
  edithardDisk->hide();
  labelmaxResolution->hide();
  editmaxResolution->hide();
  labelconsoleColor->hide();
  editconsoleColor->hide();
  editspecialEdition->hide();
}

void Productsettings::hideCoNG(){
editsupport4K->hide();
}

void Productsettings::hideCoRC(){
labelbit->hide(); editbit->hide();
}

void Productsettings::hideALL(){
  hideVideogame();
  hideVB();
  hideVL();
  hideConsole();
  hideCoNG();
  hideCoRC();
}

void Productsettings::viewTypeVB(bool vgb){
  if(vgb){
  gridWidVB();
  //SHOW VIDEOGAME
  labelPEGI->show(); editPEGI->show();
  labelGenre->show(); editGenre->show();
  editRemake->show();
  //SHOW VB
  labelDim->show(); editDim->show();
  hideVL();
  hideConsole();
  hideCoNG();
  hideCoRC();
  }
  else hideALL();
  }

void Productsettings::gridWidVL(){
  gridProduct->addWidget(labelPEGI);
  gridProduct->addWidget(editPEGI);
  gridProduct->addWidget(labelPlatform);
  gridProduct->addWidget(editPlatform);
  gridProduct->addWidget(labelGenre);
  gridProduct->addWidget(editGenre);
  gridProduct->addWidget(editRemake);
  gridProduct->addWidget(editSteelbook);
  gridProduct->addWidget(editDLC);
  gridProduct->addWidget(editActionFigure);
  gridProduct->addWidget(editsoundTrack);
  gridProduct->addWidget(labelextraContents);
  gridProduct->addWidget(editextraContents);
  gridProduct->addWidget(labelartbookPages);
  gridProduct->addWidget(editartbookPages);
  showSaveDeleteNew();
}

void Productsettings::viewTypeVL(bool vgl){
  if(vgl){
  gridWidVL();
   //SHOW VIDEOGAME
   labelPEGI->show(); editPEGI->show();
   labelGenre->show(); editGenre->show();
   editRemake->show();
   hideVB();
  //SHOW VL
   editSteelbook->show();
   editDLC->show();
   editActionFigure->show();
   editsoundTrack->show();
   labelextraContents->show(); editextraContents->show();
   labelartbookPages->show(); editartbookPages->show();
   hideConsole();
   hideCoNG();
   hideCoRC();
  }
  else hideALL();

}

void Productsettings::gridWidCoNG(){
  gridProduct->addWidget(labelControllerTechType);
  gridProduct->addWidget(editControllerTechType);
  gridProduct->addWidget(labelhardDisk);
  gridProduct->addWidget(edithardDisk);
  gridProduct->addWidget(labelmaxResolution);
  gridProduct->addWidget(editmaxResolution);
  gridProduct->addWidget(labelconsoleColor);
  gridProduct->addWidget(editconsoleColor);
  gridProduct->addWidget(editspecialEdition);
  gridProduct->addWidget(editsupport4K);
  showSaveDeleteNew();
}

void Productsettings::viewTypeCoNG(bool cng){
  if(cng){
  gridWidCoNG();
   hideVideogame();
   hideVB();
   hideVL();
  //SHOW CONSOLE
   labelControllerTechType->show(); editControllerTechType->show();
   labelhardDisk->show(); edithardDisk->show();
   labelmaxResolution->show(); editmaxResolution->show();
   labelconsoleColor->show(); editconsoleColor->show();
   editspecialEdition->show();
  //SHOW CoNG
   editsupport4K->show();
   hideCoRC();
  }
  else hideALL();
}

void Productsettings::gridWidCoRC(){
  gridProduct->addWidget(labelControllerTechType);
  gridProduct->addWidget(editControllerTechType);
  gridProduct->addWidget(labelhardDisk);
  gridProduct->addWidget(edithardDisk);
  gridProduct->addWidget(labelmaxResolution);
  gridProduct->addWidget(editmaxResolution);
  gridProduct->addWidget(labelconsoleColor);
  gridProduct->addWidget(editconsoleColor);
  gridProduct->addWidget(editspecialEdition);
  gridProduct->addWidget(labelbit);
  gridProduct->addWidget(editbit);
  showSaveDeleteNew();
}

void Productsettings::viewTypeCoRC(bool crc){
  if(crc){
  gridWidCoRC();
  hideVideogame();
  hideVB();
  hideVL();
  //SHOW CONSOLE
  labelControllerTechType->show(); editControllerTechType->show();
  labelhardDisk->show(); edithardDisk->show();
  labelmaxResolution->show(); editmaxResolution->show();
  labelconsoleColor->show(); editconsoleColor->show();
  editspecialEdition->show();
   hideCoNG();
   //SHOW CoRC
   labelbit->show(); editbit->show();
  }
  else hideALL();
}


void Productsettings::closeWindow(){
    if(isEnabled())
        this->setEnabled(0);
    else
        this->setEnabled(1);
}

void Productsettings::setNewLayout(){
  pushSaveChanges->hide();
  pushDelete->hide();
}

void Productsettings::setModLayout(){
if(editedproduct){
  editName->setText(editedproduct->getName());
  editSviluppatore->setText(editedproduct->getDeveloper());
  //*La data di inserimento in DB non voglio che sia modificabile*
  labelProductType->hide();

  /********************************************************
   *  Se l'oggetto che sto modificando è un Videogame Base
   * ******************************************************/
  if(editedproduct->getTypeProd() =="Videogame - Base"){
   VB->hide(); VL->hide(); CoNG->hide(); CoRC->hide();
   gridWidVB();

   //Restituisce l'indice del corrispondente testo
   int indexPegi = editPEGI->findText(QString::number(dynamic_cast<Base*>(editedproduct)->getPegi()));
   //Setta all'indice corretto
   editPEGI->setCurrentIndex(indexPegi);
   //Dato l'indice ritorna il testo corrispondente
   editPEGI->itemText(indexPegi);

   int indexPlatform = editPlatform->findText(dynamic_cast<Base*>(editedproduct)->getPlatform());
   editPlatform->setCurrentIndex(indexPlatform);
   editPlatform->itemText(indexPlatform);

   int indexGenre = editGenre->findText(dynamic_cast<Base*>(editedproduct)->getGenre());
   editGenre->setCurrentIndex(indexGenre);
   editGenre->itemText(indexGenre);

   editRemake->setChecked(dynamic_cast<Base*>(editedproduct)->getRemake());
   editDim->setText(QString::number(dynamic_cast<Base*>(editedproduct)->getDim()));

    }

   /**********************************************************
   *  Se l'oggetto che sto modificando è un Videogame Limited
   * *********************************************************/
   if(editedproduct->getTypeProd() =="Videogame - Limited"){
    VB->hide(); VL->hide(); CoNG->hide(); CoRC->hide();
    gridWidVL();

    //Restituisce l'indice del corrispondente testo
    int indexPegi = editPEGI->findText(QString::number(dynamic_cast<Limited*>(editedproduct)->getPegi()));
    //Setta all'indice corretto
    editPEGI->setCurrentIndex(indexPegi);
    //Dato l'indice ritorna il testo corrispondente
    editPEGI->itemText(indexPegi);


    int indexPlatform = editPlatform->findText(dynamic_cast<Limited*>(editedproduct)->getPlatform());
    editPlatform->setCurrentIndex(indexPlatform);
    editPlatform->itemText(indexPlatform);

    int indexGenre = editGenre->findText(dynamic_cast<Limited*>(editedproduct)->getGenre());
    editGenre->setCurrentIndex(indexGenre);
    editGenre->itemText(indexGenre);

     editRemake->setChecked(dynamic_cast<Limited*>(editedproduct)->getRemake());
     editSteelbook->setChecked(dynamic_cast<Limited*>(editedproduct)->getSteelbook());
     editDLC->setChecked(dynamic_cast<Limited*>(editedproduct)->getDlc());
     editActionFigure->setChecked(dynamic_cast<Limited*>(editedproduct)->getActionfigure());
     editsoundTrack->setChecked(dynamic_cast<Limited*>(editedproduct)->getSoundtrack());
     editextraContents->setText(dynamic_cast<Limited*>(editedproduct)->getExtracontents());
     editartbookPages->setText(QString::number(dynamic_cast<Limited*>(editedproduct)->getArtbookpages()));

     }

    /********************************************************
    *  Se l'oggetto che sto modificando è una Console NG
    * ******************************************************/
    if(editedproduct->getTypeProd() =="Console - Nuova Generazione"){
      VB->hide(); VL->hide(); CoNG->hide(); CoRC->hide();
      gridWidCoNG();

      int indexCTT = editControllerTechType->findText(dynamic_cast<NewGeneration*>(editedproduct)->getControllerTechType());
      editControllerTechType->setCurrentIndex(indexCTT);
      editControllerTechType->itemText(indexCTT);

      int indexHDD = edithardDisk->findText(dynamic_cast<NewGeneration*>(editedproduct)->getHardDisk());
      edithardDisk->setCurrentIndex(indexHDD);
      edithardDisk->itemText(indexHDD);

      int indexMR = editmaxResolution->findText(dynamic_cast<NewGeneration*>(editedproduct)->getMaxResolution());
      editmaxResolution->setCurrentIndex(indexMR);
      editmaxResolution->itemText(indexMR);

      editconsoleColor->setText(dynamic_cast<NewGeneration*>(editedproduct)->getConsoleColor());
      editspecialEdition->setChecked(dynamic_cast<NewGeneration*>(editedproduct)->getSpecialEdition());
      editsupport4K->setChecked(dynamic_cast<NewGeneration*>(editedproduct)->getSupport4K());

      }
     /********************************************************
     *  Se l'oggetto che sto modificando è una Console RC
     * ******************************************************/
    if(editedproduct->getTypeProd() =="Console - Retro Console"){
     VB->hide(); VL->hide(); CoNG->hide(); CoRC->hide();
     gridWidCoRC();

     int indexCTT = editControllerTechType->findText(dynamic_cast<RetroConsole*>(editedproduct)->getControllerTechType());
     editControllerTechType->setCurrentIndex(indexCTT);
     editControllerTechType->itemText(indexCTT);

     int indexHDD = edithardDisk->findText(dynamic_cast<RetroConsole*>(editedproduct)->getHardDisk());
     edithardDisk->setCurrentIndex(indexHDD);
     edithardDisk->itemText(indexHDD);

     int indexMR = editmaxResolution->findText(dynamic_cast<RetroConsole*>(editedproduct)->getMaxResolution());
     editmaxResolution->setCurrentIndex(indexMR);
     editmaxResolution->itemText(indexMR);

     editconsoleColor->setText(dynamic_cast<RetroConsole*>(editedproduct)->getConsoleColor());
     editspecialEdition->setChecked(dynamic_cast<RetroConsole*>(editedproduct)->getSpecialEdition());

     int indexBIT = editbit->findText(QString::number(dynamic_cast<RetroConsole*>(editedproduct)->getBit()));
     editbit->setCurrentIndex(indexBIT);
     editbit->itemText(indexBIT);
   }
}
pushNew->hide();
  }

void Productsettings::saveProduct(){
 if(editName->text()=="")
      QMessageBox::warning(0,"Attenzione","È necessario inserire il nome del prodotto");
 if(editSviluppatore->text()=="")
      QMessageBox::warning(0,"Attenzione","È necessario inserire il nome dello sviluppatore");
 else{
 if(editedproduct->getTypeProd() == "Videogame - Base"){
  if(editDim->text()=="")
      QMessageBox::warning(0,"Attenzione","È necessario inserire la dimensione del videogioco");

 else emit sendInsertVB(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(),
 editPEGI->currentText(),editPlatform->currentText(), editGenre->currentText(),editRemake->isChecked(),editDim->text());
}

 if(editedproduct->getTypeProd() == "Videogame - Limited"){
  if(editextraContents->text()==""){
     QMessageBox::warning(0,"Attenzione","È necessario inserire il contenuto extra. Se quest'ultimo non esiste, scrivere 'nessuno'");}
  if(editartbookPages->text()==""){
     QMessageBox::warning(0,"Attenzione","È necessario inserire il numero di pagine dell'artbook.");}

else emit sendInsertVL(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(),
editPEGI->currentText(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),
editSteelbook->isChecked(),editDLC->isChecked(),editActionFigure->isChecked(),editsoundTrack->isChecked(),
editextraContents->text(), editartbookPages->text());
 }

 if(editedproduct->getTypeProd() == "Console - Nuova Generazione"){
  if(editconsoleColor->text()=="")
    QMessageBox::warning(0,"Attenzione","È necessario inserire il colore della console");

 else emit sendInsertCoNG(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(), editControllerTechType->currentText(),edithardDisk->currentText(),
   editmaxResolution->currentText(),editconsoleColor->text(),editspecialEdition->isChecked(),editsupport4K->isChecked());
}

 if(editedproduct->getTypeProd() == "Console - Retro Console"){
  if(editconsoleColor->text()=="")
   QMessageBox::warning(0,"Attenzione","È necessario inserire il colore della console");

  else emit sendInsertCoRC(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(), editControllerTechType->currentText(),edithardDisk->currentText(),
  editmaxResolution->currentText(),editconsoleColor->text(),editspecialEdition->isChecked(), editbit->currentText());}
}
}


void Productsettings::saveDELETE(){
  emit(sendDeleteProduct(editedproduct));
}


void Productsettings::saveNEWPRODUCT(){
  Product* p=nullptr;
  if(editName->text() !="" && editSviluppatore->text() !="" ){
      if(VB->isChecked()){
          if(editDim->text() != ""){
          p= new Base(editName->text(),editSviluppatore->text(),editDataPubblicazione->date(),
          editPEGI->currentText().toInt(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),editDim->text().toInt());
          emit sendNewProduct(p);
          }
          else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
      }

     else if(VL->isChecked()){
         if(editextraContents->text() != "" && editartbookPages->text() !=""){
           p = new Limited(editName->text(),editSviluppatore->text(),editDataPubblicazione->date(),
           editPEGI->currentText().toInt(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),
           editSteelbook->isChecked(),editDLC->isChecked(),editActionFigure->isChecked(),editsoundTrack->isChecked(),editextraContents->text(),editartbookPages->text().toInt());
          emit sendNewProduct(p);
         }
         else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
       }

     else if(CoNG->isChecked()){
          if(editconsoleColor->text() !="" ){
           p = new NewGeneration(editName->text(),editSviluppatore->text(),editDataPubblicazione->date(),editControllerTechType->currentText(),
           edithardDisk->currentText(), editmaxResolution->currentText(), editconsoleColor->text(), editspecialEdition->isChecked(),editsupport4K->isChecked());
        emit sendNewProduct(p);
          }
          else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
        }

     else if(CoRC->isChecked()){
          if(editconsoleColor->text() !=""){
          p = new RetroConsole(editName->text(),editSviluppatore->text(),editDataPubblicazione->date(),editControllerTechType->currentText(),
          edithardDisk->currentText(), editmaxResolution->currentText(), editconsoleColor->text(), editspecialEdition->isChecked(), editbit->currentText().toInt());
           emit sendNewProduct(p);
          }
          else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
      }
}
  else
      QMessageBox::warning(0,"Errore","Campi vuoti! Inserisci i dati e riprova");

  }




