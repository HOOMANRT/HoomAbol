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
QString ID;
QString PhoneNumber;
int swReCaptcha=0,swDatabase = 1, swCaptcha, swPhone = 1;

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    setWindowTitle("Register");

    QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("d:\\Project\\Users3.db");
        database.open();

        GenCaptcha();
    ui->comboBox->addItem("");
        ui->comboBox->addItem("54");
        ui->comboBox->addItem("61");
        ui->comboBox->addItem("55");
        ui->comboBox->addItem("57");
        ui->comboBox->addItem("33");
        ui->comboBox->addItem("49");
        ui->comboBox->addItem("91");
        ui->comboBox->addItem("98");
        ui->comboBox->addItem("1");

}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != NULL && ui->lineEdit_2->text() !=NULL && ui->lineEdit_3->text() != NULL && ui->lineEdit_4 ->text()!= NULL){
            swCaptcha=swDatabase=1;
            QSqlQuery q, p;
            ID = ui->lineEdit->text();
            PhoneNumber = ui->comboBox->currentText() + "-" + ui->lineEdit_4->text();
            q.exec("SELECT password FROM jobSeekers WHERE id = '"+ID+"'");
            if(q.first()){
                swDatabase = 0;
            }
            p.exec("SELECT password FROM jobSeekers WHERE phoneNumber = '"+PhoneNumber+"'");
            if(p.first()){
                swPhone = 0;
            }

            CheckCaptcha();
            if(swCaptcha == 1 && swDatabase == 1 && swPhone == 1){
                QSqlQuery q;
                QString Password;
               // Username = ui->lineEdit->text();
                Password = ui->lineEdit_2->text();
                q.exec("INSERT INTO jobSeekers(id, password, phoneNumber) VALUES ('"+ID+"', '"+Password+"','"+PhoneNumber+"')");
                VerificationCode *pg4 = new VerificationCode;
                pg4->show();
                this->close();

            }
            else if(swDatabase == 0 && swCaptcha == 1 && swPhone == 1){
                QMessageBox::warning(this, "Error", "The username already exist!");
                swReCaptcha=1;
            }
            else if(swDatabase == 1 && swCaptcha == 0 && swPhone == 1){
                QMessageBox::warning(this, "Error", "Captcha code does not match!");
                swReCaptcha=1;
            }
            else if(swDatabase == 1 && swCaptcha == 1 && swPhone == 0){
                QMessageBox::warning(this, "Error", "Phone number already exist!");
                swReCaptcha=1;
            }
            else if(swDatabase == 0 && swCaptcha == 0 && swPhone == 1){
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
                swReCaptcha=1;
            }
            else if(swDatabase == 1 && swCaptcha == 0 && swPhone == 0){
                QMessageBox::warning(this,
                                     "Error",
                                     "<ul>"
                                     "<li>"
                                     "Captcha code does not match!"
                                     "</li>"
                                     "<li>"
                                     "Phone number already exist!"
                                     "</li>"
                                     "</ul>");
                swReCaptcha=1;
            }
            else if(swDatabase == 0 && swCaptcha == 1 && swPhone == 0){
                QMessageBox::warning(this,
                                     "Error",
                                     "<ul>"
                                     "<li>"
                                     "The username already exist!"
                                     "</li>"
                                     "<li>"
                                     "Phone number already exist!"
                                     "</li>"
                                     "</ul>");
                swReCaptcha=1;
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
                                     "<li>"
                                     "Phone number already exist!"
                                     "</li>"
                                     "</ul>");
                swReCaptcha=1;
            }
            if (swReCaptcha){
                GenCaptcha();
                swReCaptcha=0;
            }
        }
        else{
            QMessageBox::warning(this ,"Empty Form", "Please FILL FORM first!");
        }
}

void Register::GenCaptcha()
{
    random = rand() % 9;
    switch (random) {
    case 0:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-2.png);");
        break;
    case 1:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-3.png);");
        break;
    case 2:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-4.png);");
        break;
    case 3:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-5.png);");
        break;
    case 4:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-6.png);");
        break;
    case 5:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-7.png);");
        break;
    case 6:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-8.png);");
        break;
    case 7:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-9.png);");
        break;
    case 8:
        ui->label_3->setStyleSheet("image: url(:/captch/cap-1.png);");
        break;
    }
}

void Register::CheckCaptcha()
{
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
}

void Register::on_comboBox_activated(int index)
{
    switch (index) {
        case 1:
            ui->lineEdit_4->setPlaceholderText("Argentina");
            break;
        case 2:
            ui->lineEdit_4->setPlaceholderText("Australia");
            break;
        case 3:
            ui->lineEdit_4->setPlaceholderText("Brazil");
            break;
        case 4:
            ui->lineEdit_4->setPlaceholderText("Colombia");
            break;
        case 5:
            ui->lineEdit_4->setPlaceholderText("France");
            break;
        case 6:
            ui->lineEdit_4->setPlaceholderText("Germany");
            break;
        case 7:
            ui->lineEdit_4->setPlaceholderText("India");
            break;
        case 8:
            ui->lineEdit_4->setPlaceholderText("Iran");
            break;
        case 9:
            ui->lineEdit_4->setPlaceholderText("United States");
            break;
        }
}

