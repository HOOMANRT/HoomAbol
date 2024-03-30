#ifndef SPLASH_H
#define SPLASH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Splash; }
QT_END_NAMESPACE

class Splash : public QMainWindow
{
    Q_OBJECT

public:
    Splash(QWidget *parent = nullptr);
    ~Splash();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Splash *ui;
};
#endif // SPLASH_H
