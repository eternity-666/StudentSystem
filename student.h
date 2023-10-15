#ifndef STUDENT_H
#define STUDENT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVector>
#include <QDebug>
#include <QObject>
#include <QtGlobal>

class student : public QObject
{
    Q_OBJECT
public:
    struct stuInfo
    {
        int id;
        QString studentNumber;
        QString name;
        QString classname;
        int chinese;
        int math;
        int english;
    };

    struct userInfo
    {
        QString username;
        QString password;
        QString auth;

    };

public:
    explicit student(QObject *parent = nullptr);
     QVector<student::stuInfo> studentList;
    QVector<student::userInfo> userList;
     //查询学生所有的数量
     quint32 getStuCnt();
    //查询所有学生
     QVector<student::stuInfo> getAllStu();

     //查询第几页学生数据
     QVector<student::stuInfo> getPageStu(qint32 page,quint32 uiCnt);

     //增加学生
     bool addStu(stuInfo info);
     //删除学生
     bool delStu(int id);
     //清空学生表
     void clearStuTable();
     //修改学生信息
     void updateStuInfo(stuInfo info);
     //搜索某一个学生
    stuInfo getSomeOne(int id);

       QVector<student::userInfo> getAllUsers();

      //查询用户是否存在
      bool isExit(QString strUserName,QString password);
       //获取某一个用户
      userInfo getUser(QString strUserName);
      //修改用户权限
      bool updateUser(userInfo info);

      //添加单个用户
     bool addUser(userInfo info);

      //删除单个用户
      bool delUser(QString strUserName);

    static student* getinstance();


      static void sqlInit();




signals:

};

#endif // STUDENT_H
