#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>


extern QString ID;
extern QString PhoneNumber;
namespace Ui {



class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
