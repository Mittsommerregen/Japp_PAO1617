#ifndef LOGINWINDOW
#define LOGINWINDOW
#include<QString>
#include<QDialog>
#include<QMessageBox>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QRegExpValidator>


class LoginWindow: public QDialog{
private:
    Q_OBJECT
    QLabel * windowIcon;
    QLabel * labelNickname;
    QLabel *labelPassword;
    QLineEdit * textNickname;
    QLineEdit * textPassword;
    QPushButton *pushLogin;
    QVBoxLayout *layoutLogin;
    QGridLayout * gridLogin;

public:
    LoginWindow();
    //Se il login non va a buon fine questo metodo ripulisce i campi nickname e password
    void empty();

public slots:
    void login();

signals:
    void doLogin(const QString&, const QString&);
};
#endif // LOGINWINDOW

