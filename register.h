#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>



namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

public slots:
    void CheckCaptcha();
    void GenCaptcha();
private slots:
    void on_pushButton_clicked();



    void on_comboBox_activated(int index);

    void on_pushButton_2_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
