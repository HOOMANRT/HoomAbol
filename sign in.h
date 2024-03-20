#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
class Signup;
}

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
