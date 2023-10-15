#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stu = student::getinstance();

    addStudent = new addStudentPage();//一定要new出来不然程序会崩溃，血的教训
    update = new updateDialog();
    TableInit();
    treeWidgetInit();







}

MainWindow::~MainWindow()
{

    delete ui;
}




void MainWindow::on_exitSystem_released()
{


        close();
}




void MainWindow::on_searchButton_clicked()
{
        ui->tableWidget->clear();
        int id = ui->searchLineEdit->text().toInt();
        student::stuInfo info =  stu->getSomeOne(id);
        ui->tableWidget->setColumnCount(7);
        QStringList l;
        l<<"序号"<<"学号"<<"姓名"<<"班级"<<"语文"<<"数学"<<"英语";
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(info.id)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(info.studentNumber));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(info.name));
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(info.classname));
        ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(info.chinese)));
        ui->tableWidget->setItem(0,5,new QTableWidgetItem(QString::number(info.math)));
        ui->tableWidget->setItem(0,6,new QTableWidgetItem(QString::number(info.english)));

}
void MainWindow::treeWidgetInit()
{
        ui->treeWidget->setColumnCount(1);
        QStringList list;
        list<<"学生管理系统"<<"学生管理"<<"管理员系统";
        QTreeWidgetItem *p = new QTreeWidgetItem(ui->treeWidget,list);
        ui->treeWidget->addTopLevelItem(p);

        list.clear();
        list<<"学生管理";
        QTreeWidgetItem *p1 = new QTreeWidgetItem(p,list);
        list.clear();
        list<<"管理员管理";
        QTreeWidgetItem *p2 = new QTreeWidgetItem(p,list);

        p->addChild(p1);
        p->addChild(p2);
}

void MainWindow::updateTableInit()
{


         auto cnt = stu->getStuCnt();
        ui->tableWidget->setColumnCount(7);
        QStringList l;
        l<<"序号"<<"学号"<<"姓名"<<"班级"<<"语文"<<"数学"<<"英语";
        ui->tableWidget->setHorizontalHeaderLabels(l);

        ui->tableWidget->setRowCount(cnt);
        QVector<student::stuInfo> students = stu->getPageStu(0,cnt);

        for(int i=0;i<students.size();i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(students[i].id)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(students[i].studentNumber));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(students[i].name));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(students[i].classname));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(students[i].chinese)));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(students[i].math)));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(students[i].english)));
        }
}

void MainWindow::TableInit()
{
        ui->tableWidget->clear();
        auto cnt = stu->getStuCnt();
        stu->studentList = stu->getAllStu();
        ui->tableWidget->setColumnCount(7);
        QStringList l;
        l<<"序号"<<"学号"<<"姓名"<<"班级"<<"语文"<<"数学"<<"英语";
        ui->tableWidget->setHorizontalHeaderLabels(l);

        ui->tableWidget->setRowCount(cnt);


        //渲染
        for(int i=0;i<stu->studentList.size();i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(stu->studentList[i].id)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(stu->studentList[i].studentNumber));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(stu->studentList[i].name));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(stu->studentList[i].classname));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(stu->studentList[i].chinese)));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(stu->studentList[i].math)));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(stu->studentList[i].english)));
        }
        stu->studentList.clear();
}




void MainWindow::on_addButton_clicked()
{

       addStudent->exec();
        TableInit();


}





void MainWindow::on_clearButton_clicked()
{
     ui->tableWidget->clear();
}


void MainWindow::on_updateButton_clicked()
{
     update->exec();
      TableInit();
}


void MainWindow::on_deleteButton_clicked()
{

      int id = QInputDialog::getInt(this, tr("获取id"),tr("id"));
      if (id!=NULL)
            stu->delStu(id);
       TableInit();

}


void MainWindow::on_refreshButon_clicked()
{
       ui->tableWidget->clear();

    TableInit();
}

