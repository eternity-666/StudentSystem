#ifndef DELDIALOG_H
#define DELDIALOG_H

#include <QDialog>

namespace Ui {
class delDialog;
}

class delDialog : public QDialog
{
    Q_OBJECT

public:
    explicit delDialog(QWidget *parent = nullptr);
    ~delDialog();

private:
    Ui::delDialog *ui;
};

#endif // DELDIALOG_H
