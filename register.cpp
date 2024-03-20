#include "register.h"
#include "ui_register.h"

int random;

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

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
