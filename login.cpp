#include "login.h"
#include "ui_login.h"
#include "register.h"
//#include "verificationcode.h"
//#include "setprofile.h"
#include "mainpage.h"
#include "QMessageBox"
#include "splash.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

int theme2 = 0;
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Project\\Users3.db");
    database.open();

//    QPixmap backgroundImage(":/back-login-1.jpg");
//    backgroundImage = backgroundImage.scaled(this->size(), Qt::KeepAspectRatioByExpanding);

    //->setPixmap(backgroundImage);

}

login::~login()
{
    delete ui;
}


void login::on_pushButton_5_clicked()
{
    switch(theme2){
        case 0:
            ui->groupBox->setStyleSheet("background-color: rgb(0, 0, 0);");
            ui->label_2->setStyleSheet("color: rgb(255, 255, 255);");
            ui->label_9->setStyleSheet("color: rgb(255, 255, 255);");
            theme2++;
            break;
        case 1:
            ui->groupBox->setStyleSheet("background-color: rgb(255, 255, 255);");
            ui->label_2->setStyleSheet("color: rgb(0, 0, 0);");
            ui->label_9->setStyleSheet("color: rgb(0, 0, 0);");
            theme2--;
            break;
        }
}


void login::on_pushButton_2_clicked()
{
    Register *pg3 = new Register;
    pg3->show();
    this->close();

}


void login::on_pushButton_clicked()
{
    if(ui->lineEdit->text( ) != NULL && ui->lineEdit_2->text() != NULL ){
        QSqlQuery q;
        ID = ui->lineEdit->text();
        q.exec("SELECT password FROM jobSeekers WHERE id = '"+ID+"'");
        if(q.first()){
           QString  Password = q.value(0).toString();
            QString enterdPass = ui->lineEdit_2->text();
            if(Password == enterdPass){
                mainPage *pg4 = new mainPage;
                pg4->show();
                this->close();
            }
            else{
                QMessageBox::warning(this, "Error", "Wrong information!");
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Wrong information!");
        }
    }
    else{
        QMessageBox::information(this,"Fill Form","Please FILL FORM and try again!");
    }
}


void login::on_pushButton_3_clicked()
{
    Splash *pg1=new Splash;
    pg1->show();
    this->close();
}

