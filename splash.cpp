#include "splash.h"
#include "ui_splash.h"
#include "login.h"

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>

int textBrowser1 = 0;
int textBrowser2 = 0;
int textBrowser3 = 0;
int theme = 0;

Splash::Splash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Splash)
{
    ui->setupUi(this);




    ui->textBrowser->hide();
    ui->textBrowser_2->hide();
    ui->textBrowser_3->hide();

}

Splash::~Splash()
{
    delete ui;
}


void Splash::on_pushButton_2_clicked()
{
    if(textBrowser1 == 0){
        ui->textBrowser->show();
        textBrowser1++;
    }
    else{
        ui->textBrowser->hide();
        textBrowser1--;
    }
}


void Splash::on_pushButton_3_clicked()
{
    if(textBrowser2 == 0){
        ui->textBrowser_2->show();
        textBrowser2++;
    }
    else{
        ui->textBrowser_2->hide();
        textBrowser2--;
    }
}


void Splash::on_pushButton_4_clicked()
{
    if(textBrowser3 == 0){
        ui->textBrowser_3->show();
        textBrowser3++;
    }
    else{
        ui->textBrowser_3->hide();
        textBrowser3--;
    }
}

void Splash::on_pushButton_5_clicked()
{

    switch (theme) {
        case 0:
            ui->groupBox->setStyleSheet("background-color: rgb(2, 12, 11);");
            ui->label_2->setStyleSheet("color: rgb(255, 255, 255);");
            theme++;
            break;
        case 1:
            ui->groupBox->setStyleSheet("background-color: rgb(199, 255, 247);");
            ui->label_2->setStyleSheet("color: rgb(2, 12, 11)");
            theme--;
            break;
    }

}


void Splash::on_pushButton_clicked()
{
    login *pg2 = new login;
    pg2->show();
    this->close();
}



