#include "splash.h"
#include "ui_splash.h"
#include "login.h"
#include "verificationcode.h"
#include "register.h"

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QSize>

int textBrowser1 = 0;
int textBrowser2 = 0;
int textBrowser3 = 0;
int theme = 0;

Splash::Splash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Splash)
{
    ui->setupUi(this);

    this->setMinimumSize(1124,709);
    this->setMaximumSize(1124,709);
//    QVBoxLayout *layout = new QVBoxLayout;
//    this->setLayout(layout);
//    ui->label ->setLayout(layout);
//    ui->label_2 ->setLayout(layout);
//    ui->label_3 ->setLayout(layout);
//    ui->label_4 ->setLayout(layout);
//    ui->label_5->setLayout(layout);
//    ui->label_6 ->setLayout(layout);
//    ui->label_7 ->setLayout(layout);
//    ui->pushButton ->setLayout(layout);
//    ui->pushButton_2 ->setLayout(layout);
//    ui->pushButton_3->setLayout(layout);
//    ui->pushButton_4 ->setLayout(layout);
//    ui->pushButton_5 ->setLayout(layout);
//    ui->textBrowser->setLayout(layout);
//    ui->textBrowser_2->setLayout(layout);
//    ui->textBrowser_3->setLayout(layout);

    ui->textBrowser->hide();
    ui->textBrowser_2->hide();
    ui->textBrowser_3->hide();

    // Set the window size and position
    //this->resize(600, 400);
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());

    // Create a property animation to fade in the window
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

Splash::~Splash()
{
    delete ui;
}

void Splash::on_pushButton_2_clicked()
{
    // Toggle the visibility of the first text browser
    if (textBrowser1 == 0) {
        ui->textBrowser->show();
        textBrowser1++;
    } else {
        ui->textBrowser->hide();
        textBrowser1--;
    }
}

void Splash::on_pushButton_3_clicked()
{

    // Toggle the visibility of the second text browser
    if (textBrowser2 == 0) {
        ui->textBrowser_2->show();
        textBrowser2++;
    } else {
        ui->textBrowser_2->hide();
        textBrowser2--;
    }
}

void Splash::on_pushButton_4_clicked()
{
    // Toggle the visibility of the third text browser
    if (textBrowser3 == 0) {
        ui->textBrowser_3->show();
        textBrowser3++;
    } else {
        ui->textBrowser_3->hide();
        textBrowser3--;
    }
}

void Splash::on_pushButton_5_clicked()
{
    // Toggle the theme
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
    // Create a new login window
    login *pg2 = new login;
    pg2->show();

    // Close the splash window
    this->close();
}
