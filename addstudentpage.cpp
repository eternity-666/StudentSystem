#include "addstudentpage.h"
#include "ui_addstudentpage.h"

addStudentPage::addStudentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStudentPage)
{
    ui->setupUi(this);
    this->setFixedSize(413,440);
}

addStudentPage::~addStudentPage()
{
    delete ui;
}

void addStudentPage::on_cancelPushButton_2_clicked()
{
    close();
}


void addStudentPage::on_savePushButton_clicked()
{
    student *stu = student::getinstance();
    student::stuInfo info;
   info.studentNumber = ui->studentNumberLineEdit->text();
    info.name = ui->nameLineEdit->text();
    info.classname= ui->classNameLineEdit->text();
    info.chinese = ui->chineseLineEdit->text().toInt();
    info.math = ui->mathLineEdit->text().toInt();
    info.english = ui->englishLineEdit->text().toInt();
    stu->addStu(info);

    delete stu;

    QMessageBox::information(this,"提示","保存成功");
    this->hide();


}

