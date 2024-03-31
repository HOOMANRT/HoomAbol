#ifndef VERIFICATIONCODE_H
#define VERIFICATIONCODE_H

#include <QMainWindow>

namespace Ui {
class VerificationCode;
}

class VerificationCode : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerificationCode(QWidget *parent = nullptr);
    ~VerificationCode();

public slots:
    void verify();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();



    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

private:
    Ui::VerificationCode *ui;
};

#endif // VERIFICATIONCODE_H
