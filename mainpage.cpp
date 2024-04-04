#include "mainpage.h"
#include "ui_mainpage.h"
#include "setprofile.h"
#include "splash.h"
#include "login.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

mainPage::mainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainPage)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Project\\Users3.db");
    database.open();

    ui->groupBox_2->hide();

}

mainPage::~mainPage()
{
    delete ui;
}

void mainPage::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->groupBox_2->show();
}


void mainPage::on_pushButton_3_clicked()
{
    ui->pushButton->show();
    ui->groupBox_2->hide();
}


void mainPage::on_pushButton_2_clicked()
{
    setProfile *pg5 = new setProfile;
    pg5->show();
    this->close();
}


void mainPage::on_pushButton_4_clicked()
{
    Splash *pg1=new Splash;
    pg1->show();
    this->close();
    ID='\0';
    PhoneNumber='\0';
}

