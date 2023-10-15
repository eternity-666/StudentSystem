#include "updatedialog.h"
#include "ui_updatedialog.h"

updateDialog::updateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateDialog)
{
    ui->setupUi(this);
}

updateDialog::~updateDialog()
{
    delete ui;
}

void updateDialog::on_cancelPushButton_clicked()
{
    this->hide();
}


void updateDialog::on_admitPushButton_clicked()
{
    student * stu = student::getinstance();
    student::stuInfo info;
    info.id = ui->idIineEdit->text().toInt();
    info.studentNumber = ui->studentLineEdit->text();
    info.name = ui->nameLineEdit->text();
    info.classname= ui->classnameLineEdit->text();
    info.chinese = ui->chineseLineEdit->text().toInt();
    info.math = ui->mathLineEdit->text().toInt();
    info.english = ui->englishLineEdit->text().toInt();
    stu->updateStuInfo(info);
    delete stu;

    QMessageBox::information(this,"提示","修改成功");
    this->hide();

}

