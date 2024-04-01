#include "setprofile.h"
#include "ui_setprofile.h"
#include "login.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

int year, month, day;
int Age = 18, swJobSeekers, swEmployers;

setProfile::setProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setProfile)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\Project\\Users3.db");
    database.open();

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


void setProfile::on_dateEdit_userDateChanged(const QDate &date)
{
    year = date.year();
    month = date.month();
    day = date.day();

}




void setProfile::on_pushButton_clicked()
{
    QString Name = ui->lineEdit->text();
    QString Lastname = ui->lineEdit_2->text();
    QString PhoneNum = ui->lineEdit_3->text();

    if(swJobSeekers == 1){
        QString SchoolCollege = ui->lineEdit_4->text();
        QVariant selectedItem = ui->comboBox_3->currentData();
        QString IntendedJob = selectedItem.toString();

        QVariant selectedItem2 = ui->comboBox_4->currentData();
        QString IntendedCompany = selectedItem2.toString();
        QString Post = "Job seeker";


        QSqlQuery q;
        q.exec("UPDATE jobSeekers SET name = '"+Name+"', lastname = '"+Lastname+"', birthyear = '"+year+"', birthmonth = '"+month+"', birthday = '"+day+"', phoneNumber = '"+PhoneNum+"', schoolCollege = '"+SchoolCollege+"' , intendedJob = '"+IntendedJob+"' WHERE username = '"+Username+"'");

    }
    else{

    }




}




