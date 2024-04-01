#include "register.h"
#include "ui_register.h"
#include <iostream>
#include <QMessageBox>
#include "verificationcode.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

int random;
QString Username;

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Project\\Users3.db");
    database.open();

    random = rand() % 9;
    switch (random) {
    case 0:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144544.png);");
        break;
    case 1:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144614.png);");
        break;
    case 2:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144628.png);");
        break;
    case 3:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144650.png);");
        break;
    case 4:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144702.png);");
        break;
    case 5:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144730.png);");
        break;
    case 6:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144820.png);");
        break;
    case 7:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144835.png);");
        break;
    case 8:
        ui->label_3->setStyleSheet("image: url(:/new/prefix1/captcha.png);");
        break;

    }


}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{

    int swDatabase = 1, swCaptcha;

    QSqlQuery q;
    Username = ui->lineEdit->text();
    q.exec("SELECT password FROM jobSeekers WHERE username = '"+Username+"'");



    if(q.first()){
        swDatabase = 0;
    }

    if(random == 0){
        if(ui->lineEdit_3->text() == "4SZXT"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if(random == 1){
        if(ui->lineEdit_3->text() == "9yhx6b"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if(random == 2){
        if(ui->lineEdit_3->text() == "DELXE"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if(random == 3){
        if(ui->lineEdit_3->text() == "GJwn"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if(random == 4){
        if(ui->lineEdit_3->text() == "nc72Z"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if(random == 5){
        if(ui->lineEdit_3->text() == "6xx36dnxpm"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else if (random == 6){
        if(ui->lineEdit_3->text() == "qvpxayk"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }

    }
    else if(random == 7){
        if(ui->lineEdit_3->text() == "zXx32"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }
    else{
        if(ui->lineEdit_3->text() == "W68HP"){
            swCaptcha = 1;
        }
        else{
            swCaptcha = 0;
        }
    }

    if(swCaptcha == 1 && swDatabase == 1){
        QSqlQuery q;
        QString Password;
        Username = ui->lineEdit->text();
        Password = ui->lineEdit_2->text();
        q.exec("INSERT INTO jobSeekers(username, password) VALUES ('"+Username+"', '"+Password+"')");
        VerificationCode *pg4 = new VerificationCode;
        pg4->show();
        this->close();

    }
    else if(swDatabase == 0 && swCaptcha == 1){
        QMessageBox::warning(this, "Error", "The username already exist!");
        random = rand() % 9;
        switch (random) {
        case 0:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144544.png);");
            break;
        case 1:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144614.png);");
            break;
        case 2:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144628.png);");
            break;
        case 3:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144650.png);");
            break;
        case 4:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144702.png);");
            break;
        case 5:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144730.png);");
            break;
        case 6:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144820.png);");
            break;
        case 7:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144835.png);");
            break;
        case 8:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/captcha.png);");
            break;

        }

    }
    else if(swCaptcha == 0 && swDatabase == 1){
        QMessageBox::warning(this, "Error", "Captcha code does not match!");
        random = rand() % 9;
        switch (random) {
        case 0:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144544.png);");
            break;
        case 1:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144614.png);");
            break;
        case 2:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144628.png);");
            break;
        case 3:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144650.png);");
            break;
        case 4:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144702.png);");
            break;
        case 5:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144730.png);");
            break;
        case 6:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144820.png);");
            break;
        case 7:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144835.png);");
            break;
        case 8:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/captcha.png);");
            break;

        }
    }
    else{
        QMessageBox::warning(this,
                             "Error",
                             "<ul>"
                             "<li>"
                             "The username already exist!"
                             "</li>"
                             "<li>"
                             "Captcha code does not match!"
                             "</li>"
                             "</ul>");
        random = rand() % 9;
        switch (random) {
        case 0:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144544.png);");
            break;
        case 1:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144614.png);");
            break;
        case 2:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144628.png);");
            break;
        case 3:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144650.png);");
            break;
        case 4:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144702.png);");
            break;
        case 5:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144730.png);");
            break;
        case 6:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144820.png);");
            break;
        case 7:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/Screenshot 2024-03-20 144835.png);");
            break;
        case 8:
            ui->label_3->setStyleSheet("image: url(:/new/prefix1/captcha.png);");
            break;

        }

    }

}




