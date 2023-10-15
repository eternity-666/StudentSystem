#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     student::sqlInit();
    LoginDialog * loginWindow = new LoginDialog;
    int res = loginWindow->exec();
    if(res==QDialog::Accepted)
    {
        MainWindow * w;
        w = new MainWindow;
        w->show();
         return a.exec();
    }
    else{
         return 0;
    }
}
