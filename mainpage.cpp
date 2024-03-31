#include "mainpage.h"
#include "ui_mainpage.h"
#include "setprofile.h"

mainPage::mainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainPage)
{
    ui->setupUi(this);
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

