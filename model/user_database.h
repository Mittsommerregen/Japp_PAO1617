#ifndef USER_DATABASE
#define USER_DATABASE
#include <QMessageBox>
#include<QFile>
#include <QFileDialog>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include"user_admin.h"
#include"user_base.h"
#include"user_premium.h"

class userDatabase{
private:
    static QString filename;
    QList<User*> users;
public:
    userDatabase();
    ~userDatabase();

    //Dato un nome utente restituisce il puntatore a quell'utente
    User* getUser(const QString &text);

    //Data una o n lettere restituisce una lista di puntatori a quegli utenti che hanno una corrispondenza con tali lettere,
    //altrimenti restituisce una lista vuota
    QList<User*> userContainsWord(const QString & word) const;

    //bool isEmpty() const;

    //Dato un nickname, lo cerca nella lista di puntatori ad utenti (Metodo che serve per il cambio di nickname)
    bool findNickname(const QString &nickname);

    //Dato un nickname ed una password restituisce il puntatore a quell'utente (Metodo che serve per il login)
    User *checkUser(const QString& nickname, const QString&password);

    //Metodo utile per il cambio di categoria di appartenenza dell'utente
    void upgradeUserCategory(User *u, QString c);

    //Metodo utile per l'inserimento dell'utente nel Database
    void addUserToDB(User*u);

    //Metodo utile per la rimozione dell'utente dal Database
    void removeUserToDB(User*u);

    //Metodo che restituisce la lista di puntatori a tutti gli utenti
    const QList<User*> getAllUsers()const;

    //Metodi di caricamento e salvataggio nel DB
    void Load();
    void SaveAndClose();
};
#endif // USER_DATABASE

