#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "student.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_LoginButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::LoginDialog *ui;
    student* stu;
};

#endif // LOGINDIALOG_H
