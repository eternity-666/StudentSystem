#ifndef ADDSTUDENTPAGE_H
#define ADDSTUDENTPAGE_H

#include <QDialog>
#include "student.h"

#include <QMessageBox>
namespace Ui {
class addStudentPage;
}

class addStudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit addStudentPage(QWidget *parent = nullptr);
    ~addStudentPage();

private slots:
    void on_cancelPushButton_2_clicked();

    void on_savePushButton_clicked();

private:
    Ui::addStudentPage *ui;
};

#endif // ADDSTUDENTPAGE_H
