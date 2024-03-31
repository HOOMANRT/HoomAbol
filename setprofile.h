#ifndef SETPROFILE_H
#define SETPROFILE_H

#include <QMainWindow>

namespace Ui {
class setProfile;
}

class setProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit setProfile(QWidget *parent = nullptr);
    ~setProfile();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_pushButton_clicked();



private:
    Ui::setProfile *ui;
};

#endif // SETPROFILE_H
