#include "list.h"

DBList::DBList(productDatabase *productdb, userDatabase *userdb, QWidget *parent):
      QTableWidget(parent), productlist(productdb), userlist(userdb){
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

void DBList::viewUsers(){
    this->setRowCount(0);
    QStringList tableHeader;
    setColumnCount(4);
    setColumnWidth(0,255);
    setColumnWidth(1,210);
    setColumnWidth(2,200);
    setColumnWidth(3,265);
    setMaximumWidth(933);
    tableHeader<<"Nickname"<<"Nome"<<"Cognome"<<"Tipologia Account";
    setHorizontalHeaderLabels(tableHeader);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void DBList::addListUsers(User* user){
    int row=0;
    if(user){
        setRowCount(row+1);
        addItemUser(row,user);
    }
    else
        QMessageBox::warning(0,"Utente", "Ops! Utente non trovato, riprova!");
}

void DBList::addListUsers(QList<User*> p){
    int row=0;
    auto it=p.begin();
    for( ; it != p.end(); ++it){
        if(*it){
        setRowCount(row+1);
        addItemUser(row,*it);
        row++;
      }
    }
}

void DBList::addListAllUsers(){
    int row=0;
    QList<User*> userList= userlist->getAllUsers();
    QList<User*>::const_iterator it=userList.begin();
    for(; it!=userList.end() ;it++){
        if(*it){
            setRowCount(row+1);
            addItemUser(row,*it);
            row++;
        }
    }
}

void DBList::addItemUser(int row, User* u){
    setItem(row,0,new QTableWidgetItem(u->getNickname()));
    setItem(row,1,new QTableWidgetItem(u->getName()));
    setItem(row,2,new QTableWidgetItem(u->getSurname()));
    setItem(row,3,new QTableWidgetItem(u->getLabel()));
}

void DBList::viewProducts(){
   this->setRowCount(0);
    QStringList tableHeader;
    setColumnCount(5);
    setColumnWidth(0,200);
    setColumnWidth(1,160);
    setColumnWidth(2,205);
    setColumnWidth(3,100);
    setColumnWidth(4,250);
    setMaximumWidth(933);
    tableHeader<<"Nome"<<"Sviluppatore"<<"Data Pubblicazione"<<"Codice"<<"Tipo";
    setHorizontalHeaderLabels(tableHeader);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void DBList::addListProducts(Product *p){
    int row=0;
    if(p){
        setRowCount(row+1);
        addItemProduct(row,p);
    }
    else
        QMessageBox::warning(0,"Prodotto", "Ops! Prodotto non trovato, riprova!");

}

void DBList::addListProducts(QList<Product*> p){
    int row=0;
    auto it=p.begin();
    for( ; it != p.end(); ++it){
        if(*it){
        setRowCount(row+1);
        addItemProduct(row,*it);
        row++;
      }
    }
}



void DBList::addListAllProducts(){
    int row=0;
    QList<Product*> mainlist=productlist->getAllProducts();
    QList<Product*>::const_iterator it=mainlist.begin();
    for(; it!=mainlist.end(); it++){
        if(*it){
            setRowCount(row+1);
            addItemProduct(row,*it);
            row++;
        }
    }
}

void DBList::addItemProduct(int r, Product* p){
     setItem(r,0,new QTableWidgetItem(p->getName()));
     setItem(r,1,new QTableWidgetItem(p->getDeveloper()));
     setItem(r,2,new QTableWidgetItem(p->getDate().toString()));
     setItem(r,3,new QTableWidgetItem(QString::number(p->getSerialNumber())));
     setItem(r,4,new QTableWidgetItem(p->getTypeProd()));
}


