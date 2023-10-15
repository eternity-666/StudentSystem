#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>

namespace Ui {
class addStudent;
}

class addStudent : public QWidget
{
    Q_OBJECT

public:
    explicit addStudent(QWidget *parent = nullptr);
    ~addStudent();



public:
    Ui::addStudent *ui;

};

#endif // ADDSTUDENT_H
