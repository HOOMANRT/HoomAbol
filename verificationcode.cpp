#include "verificationcode.h"
#include "ui_verificationcode.h"
#include <iostream>
#include <QRandomGenerator>
#include <QThread>
#include <QValidator>
#include <QMessageBox>
#include "QTimer"
#include "mainpage.h"

int random2;
bool swVerify=true;

VerificationCode::VerificationCode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerificationCode)
{
    ui->setupUi(this);

    ui->label->hide();
    ui->lineEdit->setValidator(new QIntValidator);
    ui->lineEdit_2->setValidator(new QIntValidator);
    ui->lineEdit_3->setValidator(new QIntValidator);
    ui->lineEdit_4->setValidator(new QIntValidator);

    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton_2->setFocus();
    ui->pushButton_2->setDefault(true);
    ui->pushButton_2->setAutoDefault(false);

}

VerificationCode::~VerificationCode()
{
    delete ui;
}

void VerificationCode::verify()
{
    if(swVerify){
        ui->label->setText("YOU'RE VERIFIED!");
        QTimer::singleShot(2500, this, SLOT(sleep()));
        mainPage *pg5 = new mainPage;
        pg5->show();
        this->close();

    }
    else{
        QMessageBox::warning(this,"wrong code","Wrong Code! try again","OK!");
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->label->hide();
        ui->pushButton_2->setFocus();
        ui->pushButton_2->setDefault(true);
        ui->pushButton_2->setAutoDefault(false);
    }
}

void VerificationCode::on_pushButton_2_clicked()
{
    //create 4digit random Num
    int min = 1000;
    int max = 9999;
    random2 = QRandomGenerator::global()->bounded(min, max + 1);

    //Sleep for label

    ui->label->setNum(random2);
    QThread::sleep(3);

    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);

    ui->label->show();
    ui->lineEdit->setFocus();
}


void VerificationCode::on_pushButton_clicked()
{
    int thousand = random2 / 1000;
    int hundred = random2 / 100 - (thousand * 10);
    int ten = random2 / 10 - (thousand * 100 + hundred * 10);
    int one = random2 - (thousand * 1000 + hundred * 100 + ten * 10);
    if(ui->lineEdit->text().toInt() != thousand){
        //QMessageBox::warning(this, "Wrong code", "Try again!");
        swVerify=false;
    }
    else if(ui->lineEdit_2->text().toInt() != hundred){
        //QMessageBox::warning(this, "Wrong code", "Try again!");
        swVerify=false;
    }
    else if(ui->lineEdit_3->text().toInt() != ten){
        //QMessageBox::warning(this, "Wrong code", "Try again!");
        swVerify=false;
    }
    else if(ui->lineEdit_4->text().toInt() != one){
        //QMessageBox::warning(this, "Wrong code", "Try again!");
        swVerify=false;
    }

    verify();
     if(swVerify){

     }
     else{
         swVerify=true;
     }

}


void VerificationCode::on_lineEdit_textChanged(const QString &text)
{
    if (text.length() > 1)
    {
        ui->lineEdit->setText(text.left(1));
        return;
    }
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_2->setFocus();
}


void VerificationCode::on_lineEdit_2_textChanged(const QString &text)
{
    if (text.length() > 1)
    {
        ui->lineEdit_2->setText(text.left(1));
        return;
    }
    if(text.length()==0){
        ui->lineEdit->setFocus();
        return;
    }
    ui->lineEdit_3->setFocus();
}


void VerificationCode::on_lineEdit_3_textChanged(const QString &text)
{
    if (text.length() > 1)
    {
        ui->lineEdit_3->setText(text.left(1));
        return;
    }
    if(text.length()==0){
        ui->lineEdit_2->setFocus();
        return;
    }
    ui->lineEdit_4->setFocus();
}


void VerificationCode::on_lineEdit_4_textChanged(const QString &text)
{
    if (text.length() > 1)
    {
        ui->lineEdit_4->setText(text.left(1));
        return;
    }
    if(text.length()==0){
        ui->lineEdit_3->setFocus();
        return;
    }
    ui->pushButton->setFocus();
    ui->pushButton->setDefault(true);
    ui->pushButton->setAutoDefault(false);
}

