#include "logindialog.h"
#include "ui_logindialog.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    stu = student::getinstance();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{
    QRegularExpression rx("^[A-Za-z0-9]+([\\_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");
    QString userName = ui->accountLineEdit->text();
     QString password = ui->passwordLineEdit->text();
    QRegularExpressionMatch match = rx.match(userName);

    if(!match.hasMatch())
    {
        QMessageBox::information(this,"提示","请确保账号为合法邮箱地址后重新输入");
        ui->accountLineEdit->clear();
        ui->accountLineEdit->setFocus();
        return;

    }
    else
    {
        if(stu->isExit(userName,password))
        {
            QMessageBox::information(this,"提示","登录成功");
            done(Accepted);

        }
        else
        {
            QMessageBox::critical(this,"错误","账号或密码不正确");
            ui->accountLineEdit->clear();
            ui->passwordLineEdit->clear();


        }

    }

}


void LoginDialog::on_CancelButton_clicked()
{
    exit(0);
}

