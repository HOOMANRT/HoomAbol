#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>

namespace Ui {
class mainPage;
}

class mainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainPage(QWidget *parent = nullptr);
    ~mainPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::mainPage *ui;
};

#endif // MAINPAGE_H
