#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "updatedialog.h"
#include <QDebug>
#include <addstudentpage.h>
#include <QStringList>
#include <QMessageBox>
#include <QInputDialog>
#include <QThread>
#include <QTableWidget>


#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();







private slots:


    void on_exitSystem_released();



    void on_searchButton_clicked();

    void on_addButton_clicked();



    void on_clearButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_refreshButon_clicked();

private:
    void treeWidgetInit();

    void updateTableInit();
    void TableInit();

private:
    Ui::MainWindow *ui;
    student* stu;
    addStudentPage *addStudent;
    updateDialog *update;










};

#endif // MAINWINDOW_H
