#include "signup.h"
#include "ui_signup.h"
#include "register.h"
#include <iostream>

int theme2 = 0;

Signup::Signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pushButton_5_clicked()
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


void Signup::on_pushButton_2_clicked()
{
    Register *pg3 = new Register;
    pg3->show();
}

