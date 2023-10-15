#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>
#include <student.h>
#include <QMessageBox>

namespace Ui {
class updateDialog;
}

class updateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updateDialog(QWidget *parent = nullptr);
    ~updateDialog();

private slots:
    void on_cancelPushButton_clicked();

    void on_admitPushButton_clicked();

private:
    Ui::updateDialog *ui;
};

#endif // UPDATEDIALOG_H
