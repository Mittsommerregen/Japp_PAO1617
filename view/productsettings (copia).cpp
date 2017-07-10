#include "productsettings.h"

Productsettings::Productsettings(User *u, Product *prod): user(u), editedproduct(prod){
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowFlags(windowFlags()  & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Gestione Prodotto");
    addLayout();
    setModal(1);
}



void Productsettings::viewTypeVB(bool vgb){
    if(vgb) {
    prodWidget->show();
    videogameWidget->show();
    videogameBaseWidget->show();
    videogameLimitedWidget->hide();
    consoleWidget->hide();
    consoleNGWidget->hide();
    consoleRCWidget->hide();
   }
}

void Productsettings::viewTypeVL(bool vgl){
    if(vgl){
        prodWidget->show();
        videogameWidget->show();
        videogameBaseWidget->hide();
        videogameLimitedWidget->show();
        consoleWidget->hide();
        consoleNGWidget->hide();
        consoleRCWidget->hide();
    }
}


void Productsettings::viewTypeCoNG(bool cng){
    if(cng){
        prodWidget->show();
        videogameWidget->hide();
        videogameBaseWidget->hide();
        videogameLimitedWidget->hide();
        consoleWidget->show();
        consoleNGWidget->show();
        consoleRCWidget->hide();
    }
}

void Productsettings::viewTypeCoRC(bool crc){
    if(crc){
        prodWidget->show();
        videogameWidget->hide();
        videogameBaseWidget->hide();
        videogameLimitedWidget->hide();
        consoleWidget->show();
        consoleNGWidget->hide();
        consoleRCWidget->show();
    }
}


void Productsettings::addLayout(){

    /* PRODOTTO GENERICO */
    QGroupBox * Prod = new QGroupBox(tr("Prodotto"));

    prodWidget = new QWidget();
    QVBoxLayout *vbox0 = new QVBoxLayout(prodWidget);

    /*  CAMPI COMUNI PER OGNI PRODOTTO */
    labelName=new QLabel("Nome");
    labelSviluppatore=new QLabel("Sviluppatore");
    labelDataPubblicazione=new QLabel("Data Pubblicazione");

    editName=new QLineEdit();
    editName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    editName->setPlaceholderText("Inserisci nome");

    editSviluppatore=new QLineEdit();
    editSviluppatore->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    editSviluppatore->setPlaceholderText("Inserisci sviluppatore");

    editDataPubblicazione= new QDateTimeEdit(QDateTime::currentDateTime());
    editDataPubblicazione->setMinimumDateTime(QDateTime::currentDateTime().addYears(-20)); //oppure adddays
    editDataPubblicazione->setMaximumDateTime(QDateTime::currentDateTime().addYears(5));
    editDataPubblicazione->setDisplayFormat("yyyy.MM.dd hh:mm:ss");


    vbox0->addWidget(labelName);
    vbox0->addWidget(editName);
    vbox0->addWidget(labelSviluppatore);
    vbox0->addWidget(editSviluppatore);
    vbox0->addWidget(labelDataPubblicazione);
    vbox0->addWidget(editDataPubblicazione);
    vbox0->addStretch(1);
    Prod->setLayout(vbox0);


    /*SCELTA CATEGORIA E SOTTOCATEGORIA*/
    labelProductType = new QLabel("Tipologia prodotto:");

    VB = new QRadioButton("Videogioco Base", this);
    VL = new QRadioButton("Videogioco Limited", this);
    CoNG = new QRadioButton("Console Nuova Generazione", this);
    CoRC = new QRadioButton("Console RetroConsole", this);


    /* VIDEOGIOCO GENERICO */

    QGroupBox * Videogame = new QGroupBox(tr("Videogioco"));
    videogameWidget = new QWidget();
    QVBoxLayout *vbox1 = new QVBoxLayout(videogameWidget);

    labelPEGI = new QLabel("PEGI");
    labelPlatform = new QLabel("Piattaforma");
    labelGenre = new QLabel("Genere");
    labelRemake = new QLabel("Remake");

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


    vbox1->addWidget(labelPEGI);
    vbox1->addWidget(editPEGI);
    vbox1->addWidget(labelPlatform);
    vbox1->addWidget(editPlatform);
    vbox1->addWidget(labelGenre);
    vbox1->addWidget(editGenre);
    vbox1->addWidget(labelRemake);
    vbox1->addWidget(editRemake);
    vbox1->addStretch(1);
    Videogame->setLayout(vbox1);

   /*VIDEOGIOCO BASE*/
   QGroupBox * VGBase = new QGroupBox(tr("Videogioco Base"));
   videogameBaseWidget = new QWidget();
   QVBoxLayout *vbox2 = new QVBoxLayout(videogameBaseWidget);

   labelDim = new QLabel("Dimensione");
   editDim= new QLineEdit();
   editDim->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));
   editDim->setPlaceholderText("Inserisci dimensione");

   vbox2->addWidget(labelDim);
   vbox2->addWidget(editDim);
   vbox2->addStretch(2);
   VGBase->setLayout(vbox2);

    /* VIDEOGIOCO LIMITED */
   QGroupBox * VGLimited = new QGroupBox(tr("Videogioco Limited"));
   videogameLimitedWidget = new QWidget();
   QVBoxLayout *vbox3 = new QVBoxLayout(videogameLimitedWidget);
   labelSteelbook = new QLabel("Steelbook");
   labelDLC = new QLabel("DLC");
   labelActionFigure = new QLabel("Action Figure");
   labelsoundTrack = new QLabel("Soundtrack");
   labelextraContents = new QLabel("Contenuti Extra");
   labelartbookPages = new QLabel("Numero pagine artbook");

   editSteelbook = new QCheckBox(tr("Steelbook"));
   editDLC = new QCheckBox(tr("DLC"));
   editActionFigure = new QCheckBox(tr("Action Figure"));
   editsoundTrack = new QCheckBox(tr("Soundtrack"));
   editextraContents = new QLineEdit();
   editextraContents->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,15}")));
   editextraContents->setPlaceholderText("Inserisci contenuti extra");

   editartbookPages = new QLineEdit();
   editartbookPages->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));;
   editartbookPages->setPlaceholderText("Inserisci numero delle pagine dell'Artbook");

   vbox3->addWidget(labelSteelbook);
   vbox3->addWidget(editSteelbook);
   vbox3->addWidget(labelDLC);
   vbox3->addWidget(editDLC);
   vbox3->addWidget(labelActionFigure);
   vbox3->addWidget(editActionFigure);
   vbox3->addWidget(labelsoundTrack);
   vbox3->addWidget(editsoundTrack);
   vbox3->addWidget(labelextraContents);
   vbox3->addWidget(editextraContents);
   vbox3->addWidget(labelartbookPages);
   vbox3->addWidget(editartbookPages);
   vbox3->addStretch(3);
   VGLimited->setLayout(vbox3);


    /* CONSOLE GENERICA */
    QGroupBox * Console = new QGroupBox(tr("Console"));
    consoleWidget = new QWidget();
    QVBoxLayout *vbox4 = new QVBoxLayout(consoleWidget);
    labelControllerTechType= new QLabel("Tecnologia Controller");
    labelhardDisk = new QLabel("Hard Disk");
    labelmaxResolution = new QLabel("Risoluzione Massima");
    labelconsoleColor = new QLabel("Colore Console");
    labelspecialEdition = new QLabel("Edizione Speciale");

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

    vbox4->addWidget(labelControllerTechType);
    vbox4->addWidget(editControllerTechType);
    vbox4->addWidget(labelhardDisk);
    vbox4->addWidget(edithardDisk);
    vbox4->addWidget(labelmaxResolution);
    vbox4->addWidget(editmaxResolution);
    vbox4->addWidget(labelconsoleColor);
    vbox4->addWidget(editconsoleColor);
    vbox4->addWidget(labelspecialEdition);
    vbox4->addWidget(editspecialEdition);
    vbox4->addStretch(4);
    Console->setLayout(vbox4);

    /* CONSOLE NEWGEN */
    QGroupBox* CNG = new QGroupBox(tr("Console Nuova Generazione"));
    consoleNGWidget = new QWidget();
    QVBoxLayout *vbox5 = new QVBoxLayout(consoleNGWidget);
    labelsupport4K = new QLabel("Supporto4K");
    editsupport4K = new QCheckBox(tr("Supporto 4K"));
    vbox5->addWidget(labelsupport4K);
    vbox5->addWidget(editsupport4K);
    vbox5->addStretch(5);
    CNG->setLayout(vbox5);

    /* CONSOLE RETROCONSOLE */
    QGroupBox* CRC = new QGroupBox(tr("Console RetroConsole"));
    consoleRCWidget = new QWidget();
    QVBoxLayout *vbox6 = new QVBoxLayout(consoleRCWidget);
    labelbit = new QLabel("Bit");
    editbit = new QComboBox();
    editbit->addItem("8 bit");
    editbit->addItem("16 bit");
    editbit->addItem("32 bit");
    vbox6->addWidget(labelbit);
    vbox6->addWidget(editbit);
    vbox6->addStretch(6);
    CRC->setLayout(vbox6);

    pushSaveChanges=new QPushButton("Salva le modifiche");
    pushDelete=new QPushButton("Elimina il prodotto");
    pushNew=new QPushButton("Crea nuovo prodotto");

/*
 *
    gridProduct=new QGridLayout;
    gridProduct->addWidget(labelName, 0,0);
    gridProduct->addWidget(editName,0,1);
    gridProduct->addWidget(labelSviluppatore,1,0);
    gridProduct->addWidget(editSviluppatore,1,1);
    gridProduct->addWidget(labelDataPubblicazione,2,0);
    gridProduct->addWidget(labelProductType,3,0);
    gridProduct->addWidget(editProductType,3,1);

    VIDEOGIOCO BASE  - LIMITED
    gridProduct->addWidget(labelPEGI,4,0);
    gridProduct->addWidget(editPEGI,4,1);
    gridProduct->addWidget(labelPlatform,5,0);
    gridProduct->addWidget(editPlatform,5,1);
    gridProduct->addWidget(labelGenre,6,0);
    gridProduct->addWidget(editGenre,6,1);
    gridProduct->addWidget(editRemake,7,0);

    gridProduct->addWidget(labelDim,8,0);
    gridProduct->addWidget(editDim, 8,1);

    gridProduct->addWidget(labelSteelbook,9,0);
    gridProduct->addWidget(editSteelbook,9,1);
    gridProduct->addWidget(labelDLC,10,0);
    gridProduct->addWidget(editDLC,10,1);
    gridProduct->addWidget(labelActionFigure,11,0);
    gridProduct->addWidget(editActionFigure, 11,1);
    gridProduct->addWidget(labelsoundTrack,12,0);
    gridProduct->addWidget(editsoundTrack,12,1);
    gridProduct->addWidget(labelextraContents,13,0);
    gridProduct->addWidget(editextraContents, 13,1);
    gridProduct->addWidget(labelartbookPages,14,0);
    gridProduct->addWidget(editartbookPages,14,1);


     CONSOLE NEW - RETRO

    gridProduct->addWidget(labelControllerTechType,15,0);
    gridProduct->addWidget(editControllerTechType, 15,1);
    gridProduct->addWidget(labelhardDisk,16,0);
    gridProduct->addWidget(edithardDisk,16,1);
    gridProduct->addWidget(labelmaxResolution,17,0);
    gridProduct->addWidget(editmaxResolution, 17,1);
    gridProduct->addWidget(labelconsoleColor,18,0);
    gridProduct->addWidget(editconsoleColor,18,1);
    gridProduct->addWidget(labelspecialEdition,19,0);
    gridProduct->addWidget(editspecialEdition, 19,1);

    gridProduct->addWidget(labelsupport4K,20,0);
    gridProduct->addWidget(editsupport4K,21,1);

    gridProduct->addWidget(labelbit,22,0);
    gridProduct->addWidget(editbit,22,1);


    gridProduct->addWidget(pSalvaModifiche,23,0);
    gridProduct->addWidget(pElimina,24,1);
    gridProduct->addWidget(pCrea,25,0);
    gridProduct->addWidget(pAggiungi,26,0);

*/

    /*layoutProduct=new QVBoxLayout();
    layoutProduct->addLayout(vbox0);
    if(VB->isChecked()){
        layoutProduct->addLayout(vbox1);
        layoutProduct->addLayout(vbox2);
    }
    if(VL->isChecked()){
        layoutProduct->addLayout(vbox1);
        layoutProduct->addLayout(vbox3);
    }
    if(CoNG->isChecked()){
        layoutProduct->addLayout(vbox4);
        layoutProduct->addLayout(vbox5);
    }
    if(CoRC->isChecked()){
        layoutProduct->addLayout(vbox4);
        layoutProduct->addLayout(vbox6);
    }*/

    connect(VB,SIGNAL(toggled(bool)),this,SLOT(viewTypeVB(bool)));

    connect(VL, SIGNAL(toggled(bool)),this,SLOT(viewTypeVL(bool)));

    connect(CoNG,SIGNAL(toggled(bool)),this,SLOT(viewTypeCoNG(bool)));

    connect(CoRC,SIGNAL(toggled(bool)),this,SLOT(viewTypeCoRC(bool)));

    connect(pushSaveChanges,SIGNAL(clicked()),this,SLOT(saveProduct()));
    connect(pushDelete,SIGNAL(clicked()),this,SLOT(saveDELETE()));
    connect(pushNew,SIGNAL(clicked(bool)),this,SLOT(saveNEWPRODUCT()));
    //setLayout(layoutProduct);

}


void Productsettings::setNewLayout(){
    pushSaveChanges->hide();
    pushDelete->hide();
   // pushAdd>hide();
}

void Productsettings::setModLayout(){
    if(editedproduct){
        editName->setText(editedproduct->getName());
        editSviluppatore->setText(editedproduct->getDeveloper());
        //*La data di inserimento in DB non voglio che sia modificabile*
        if(VB->isChecked()){
        editPEGI->setCurrentText(QString::number(dynamic_cast<Base*>(editedproduct)->getPegi()));
        editPlatform->setCurrentText(dynamic_cast<Base*>(editedproduct)->getPlatform());
        editGenre->setCurrentText(dynamic_cast<Base*>(editedproduct)->getGenre());
        if(editRemake->isChecked())
            editRemake->setCheckable(true);
        else editRemake->setCheckable(false);
        editDim->setText(QString::number(dynamic_cast<Base*>(editedproduct)->getDim()));
        }

        if(VL->isChecked()){
         editPEGI->setCurrentText(QString::number(dynamic_cast<Base*>(editedproduct)->getPegi()));
         editPlatform->setCurrentText(dynamic_cast<Base*>(editedproduct)->getPlatform());
         editGenre->setCurrentText(dynamic_cast<Base*>(editedproduct)->getGenre());
         if(editRemake->isChecked()) editRemake->setCheckable(true);
         else editRemake->setCheckable(false);

          if(editSteelbook->isChecked()) editSteelbook->setCheckable(true);
          else editSteelbook->setCheckable(false);

          if(editDLC->isChecked()) editDLC->setCheckable(true);
          else editDLC->setCheckable(false);

          if(editActionFigure->isChecked()) editActionFigure->setCheckable(true);
          else editActionFigure->setCheckable(false);

          if(editsoundTrack->isChecked()) editsoundTrack->setCheckable(true);
          else editsoundTrack->setCheckable(false);

          editextraContents->setText(dynamic_cast<Limited*>(editedproduct)->getExtracontents());

          editartbookPages->setText(QString::number(dynamic_cast<Limited*>(editedproduct)->getArtbookpages()));

        }

        if(CNG->isChecked()){
        editControllerTechType->setCurrentText(dynamic_cast<NewGeneration*>(editedproduct)->getControllerTechType());
        edithardDisk->setCurrentText(QString::number(dynamic_cast<NewGeneration*>(editedproduct)->getHardDisk()));
        editmaxResolution->setCurrentText(dynamic_cast<NewGeneration*>(editedproduct)->getMaxResolution());
        editconsoleColor->setText(dynamic_cast<NewGeneration*>(editedproduct)->getConsoleColor());
        if(editspecialEdition->isChecked()) editspecialEdition->setCheckable(true);
        else editspecialEdition->setCheckable(false);
        if(editsupport4K->isChecked()) editsupport4K->setCheckable(true);
        else editsupport4K->setCheckable(false);
        }
        else{ // CRC
            editControllerTechType->setCurrentText(dynamic_cast<RetroConsole*>(editedproduct)->getControllerTechType());
            edithardDisk->setCurrentText(QString::number(dynamic_cast<RetroConsole*>(editedproduct)->getHardDisk()));
            editmaxResolution->setCurrentText(dynamic_cast<RetroConsole*>(editedproduct)->getMaxResolution());
            editconsoleColor->setText(dynamic_cast<RetroConsole*>(editedproduct)->getConsoleColor());
            if(editspecialEdition->isChecked()) editspecialEdition->setCheckable(true);
            else editspecialEdition->setCheckable(false);
            editbit->setCurrentText(QString::number(dynamic_cast<RetroConsole*>(editedproduct)->getBit()));
    }

    }
    pushNew->hide();
}



void Productsettings::saveProduct(){
   if(editName->text()==""){
        QMessageBox::warning(0,"Attenzione","È necessario inserire il nome del prodotto");
   }
   if(editSviluppatore->text()==""){
        QMessageBox::warning(0,"Attenzione","È necessario inserire il nome dello sviluppatore");
   }
   else{
       if(VB->isChecked()){
           if(editDim->text()==""){
               QMessageBox::warning(0,"Attenzione","È necessario inserire la dimensione del videogioco");}
           else{ emit sendInsertVB(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text() , editPEGI->currentText(),editPlatform->currentText(),
                                   editGenre->currentText(),editRemake->isChecked(),editDim->text());}


       }
       if(VL->isChecked()){
           if(editextraContents->text()=="" && editartbookPages->text()==""){
           QMessageBox::warning(0,"Attenzione","È necessario inserire il numero di pagine dell'artbook e il contenuto speciale. Se quest'ultimo non esiste, scrivere NO");}
           else{ emit sendInsertVL(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(),
                                   editPEGI->currentText(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),
                                   editSteelbook->isChecked(),editDLC->isChecked(),editActionFigure->isChecked(),editsoundTrack->isChecked(),editextraContents->text(),
                                   editartbookPages->text());}
            }
       if(CoNG->isChecked()){
           if(editconsoleColor->text()==""){
               QMessageBox::warning(0,"Attenzione","È necessario inserire il colore della console");}
           else{ emit sendInsertCoNG(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(), editControllerTechType->currentText(),edithardDisk->currentText(),
                                     editmaxResolution->currentText(),editconsoleColor->text(),editspecialEdition->isChecked(),editsupport4K->isChecked());}
            }
       if(CoRC->isChecked()){
           if(editconsoleColor->text()==""){
               QMessageBox::warning(0,"Attenzione","È necessario inserire il colore della console");}
            else{ emit sendInsertCoRC(editedproduct,user,editName->text(),editSviluppatore->text(), editDataPubblicazione->text(), editControllerTechType->currentText(),edithardDisk->currentText(),
                                      editmaxResolution->currentText(),editconsoleColor->text(),editspecialEdition->isChecked(), editbit->currentText());}
        }

}
}


void Productsettings::saveDELETE(){
    emit(sendDeleteProduct(editedproduct));
}


void Productsettings::saveNEWPRODUCT(){
    Product* p=nullptr;
    if(editName->text() !="" && editSviluppatore->text() !="" ){

        if(VB->isChecked()){ //Voglio salvare un videogioco base
            if(editDim->text() != ""){
            p= new Base(editName->text(),editSviluppatore->text(),editDataPubblicazione->dateTime(),
            editPEGI->currentText().toInt(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),editDim->text().toInt());
            } else {
                QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
            }
        }

        if(VL->isChecked()){ //Voglio salvare un videogioco limited
            if(editextraContents->text() != "" && editartbookPages->text() !=""){
             p = new Limited(editName->text(),editSviluppatore->text(),editDataPubblicazione->dateTime(),
             editPEGI->currentText().toInt(),editPlatform->currentText(),editGenre->currentText(),editRemake->isChecked(),
             editSteelbook->isChecked(),editDLC->isChecked(),editActionFigure->isChecked(),editsoundTrack->isChecked(),editextraContents->text(),editartbookPages->text().toInt());
            }  else {
                QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
            }
         }

        if(CoNG->isChecked()){ //Voglio salvare una console nuova generazione
            if(editconsoleColor->text() !="" ){
             p = new NewGeneration(editName->text(),editSviluppatore->text(),editDataPubblicazione->dateTime(),editControllerTechType->currentText(),
             edithardDisk->currentText().toInt(), editmaxResolution->currentText(), editconsoleColor->text(), editspecialEdition->isChecked(),editsupport4K->isChecked());
          }  else {
                QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
            }
          }

        if(CoRC->isChecked()){ //Voglio salvare una retro console
            if(editconsoleColor->text() !=""){
            p = new RetroConsole(editName->text(),editSviluppatore->text(),editDataPubblicazione->dateTime(),editControllerTechType->currentText(),
            edithardDisk->currentText().toInt(), editmaxResolution->currentText(), editconsoleColor->text(), editspecialEdition->isChecked(), editbit->currentText().toInt());
            }  else {
                QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
            }
        }

       emit sendNewProduct(p);
       }

    else{
        QMessageBox::warning(0,"Errore","Alcuni campi sono vuoti! Inserisci i dati");
   }
}




void Productsettings::disattivaFinestraIntermedia(){
    if(isEnabled()){
        this->setEnabled(0);
    }
    else{
        this->setEnabled(1);
    }
}

