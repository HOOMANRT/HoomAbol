#include "setprofile.h"
#include "ui_setprofile.h"
#include "login.h"
#include "QString"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"


QString year, month, day;
int swJobSeekers, swEmployers;
QString userName,lastName;

setProfile::setProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setProfile)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Project\\Users3.db");
    database.open();

    QSqlQuery q;
    q.exec("SELECT name FROM jobSeekers WHERE id='"+ID+"'");
    if(q.first()){
        userName=(q.value(0).toString());
        if(userName!=NULL){
            ui->lineEdit->setPlaceholderText(QString("%1").arg(userName));
        }
        else{
            ui->lineEdit->setPlaceholderText("Enter your Name :) ");
        }
    }
    q.exec("SELECT lastname FROM jobSeekers WHERE id='"+ID+"'");
    if(q.first()){
        lastName=(q.value(0).toString());
        if(lastName!=NULL){
            ui->lineEdit_2->setPlaceholderText(QString("%1").arg(lastName));
        }
        else{
            ui->lineEdit_2->setPlaceholderText("Enter your LastName :) ");
        }
    }

    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);

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

    QStringList months = (QStringList()
                          <<""
                          <<"Jan"
                          <<"Feb"
                          <<"March"
                          <<"April"
                          <<"May"
                          <<"June"
                          <<"July"
                          <<"August"
                          <<"Sep"
                          <<"Oct"
                          <<"Nov"
                          <<"Dec");
    ui->comboBox_5->addItems(months);

    QStringList days = (QStringList()
                        << "" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15" << "16"
                        << "17" << "18" << "19" <<"20" << "21" << "22" << "23" << "24" << "25" << "26" << "27" << "28" << "29" << "30" << "31");
    ui->comboBox_6->addItems(days);

    for(int comboYear = 1940; comboYear <= 2023; comboYear++){
        ui->comboBox_7->addItem(QString::number(comboYear));
    }


    ui->comboBox_2->addItem("");
    ui->comboBox_2->addItem("Job seeker");
    ui->comboBox_2->addItem("Employer");

    QStringList Jobs = (QStringList()
                        <<""
                        <<"Administration"
                        <<"Web programming"
                        <<"Marketing"
                        <<"Health services"
                        <<"Consulting"
                        <<"Quality control"
                        <<"AI"
                        <<"Information technology"
                        <<"Human resources"
                        <<"Product management"
                        <<"Business development"
                        <<"Finance"
                        <<"Accountancy"
                        <<"Software programming");

    ui->comboBox_3->addItems(Jobs);

    QStringList Companies = (QStringList()
                             <<""
                             <<"NTT"
                             <<"Stellantis"
                             <<"TNO"
                             <<"Orange"
                             <<"Generali"
                             <<"KPMG"
                             <<"SNCF"
                             <<"Siemens"
                             <<"Adidas"
                             <<"Microsoft"
                             <<"ING");

    ui->comboBox_4->addItems(Companies);

    ui->lineEdit_3->setValidator(new QIntValidator);
}

setProfile::~setProfile()
{
    delete ui;
}

void setProfile::on_comboBox_activated(int index)
{
    switch (index) {
    case 1:
        ui->lineEdit_3->setPlaceholderText("Argentina");
        break;
    case 2:
        ui->lineEdit_3->setPlaceholderText("Australia");
        break;
    case 3:
        ui->lineEdit_3->setPlaceholderText("Brazil");
        break;
    case 4:
        ui->lineEdit_3->setPlaceholderText("Colombia");
        break;
    case 5:
        ui->lineEdit_3->setPlaceholderText("France");
        break;
    case 6:
        ui->lineEdit_3->setPlaceholderText("Germany");
        break;
    case 7:
        ui->lineEdit_3->setPlaceholderText("India");
        break;
    case 8:
        ui->lineEdit_3->setPlaceholderText("Iran");
        break;
    case 9:
        ui->lineEdit_3->setPlaceholderText("United States");
        break;
    }

}


void setProfile::on_comboBox_2_activated(int index)
{
    switch (index) {
    case 1:
        ui->groupBox_5->setEnabled(true);
        ui->groupBox_4->setEnabled(false);
        swJobSeekers = 1;
        swEmployers = 0;
        break;
    case 2:
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(false);
        swJobSeekers = 0;
        swEmployers = 1;
        break;
    }
}





void setProfile::on_pushButton_clicked()
{
    QString Name = ui->lineEdit->text();
    QString Lastname = ui->lineEdit_2->text();
    QString PhoneNum = ui->comboBox->currentText() + '-' + ui->lineEdit_3->text();

    month = ui->comboBox_5->currentText();
    day = ui->comboBox_6->currentText();
    year = ui->comboBox_7->currentText();

    QString Birthday = month + "," + day + "," + year;

    QSqlQuery q;
    q.exec("UPDATE jobSeekers SET name = '"+Name+"' , lastname = '"+Lastname+"', phoneNumber = '"+PhoneNum+"' , birthday = '"+Birthday+"' WHERE id = '"+ID+"'");

    if(swJobSeekers == 1){
        QString SchoolCollege = ui->lineEdit_4->text();
        QString IntendedJob = ui->comboBox_3->currentText();
        QString IntendedCompany = ui->comboBox_4->currentText();

        q.exec("UPDATE jobSeekers SET schoolCollege = '"+SchoolCollege+"', job = '"+IntendedJob+"', company = '"+IntendedCompany+"' WHERE id = '"+ID+"'");

    }
    else{

    }




}




