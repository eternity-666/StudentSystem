#include "student.h"
#include <QSqlQuery>
student::student(QObject *parent)
    : QObject{parent}
{

}

quint32 student::getStuCnt()
{
    QSqlQuery query;
    QString sql = QString("select count(id) from student");
    quint32 uiCnt = 0;
    query.exec(sql);
    while(query.next())
    {
        uiCnt = query.value(0).toInt();
    }
    return uiCnt;
}

QVector<student::stuInfo> student::getAllStu()
{
    QSqlQuery query;
    QString sql = QString("select * from student");
    stuInfo st;
    if(query.exec(sql))
    {
        while(query.next())
        {

            st.id = query.value(0).toInt();
            st.studentNumber = query.value(1).toString();
            st.name = query.value(2).toString();
            st.classname = query.value(3).toString();
            st.chinese = query.value(4).toInt();
            st.math = query.value(5).toInt();
            st.english = query.value(5).toInt();
            studentList.push_back(st);



        }
        return studentList;

    }


}

QVector<student::stuInfo> student::getPageStu(qint32 page, quint32 uiCnt)
{
    QSqlQuery query;
    QString sql = QString("select * from student order by id limit %1 offset %2").arg(uiCnt).arg(page *uiCnt);

    stuInfo st;
    if(query.exec(sql))
    {
        while(query.next())
        {

            st.id = query.value(0).toInt();
            st.studentNumber = query.value(1).toString();
            st.name = query.value(2).toString();
            st.classname = query.value(3).toString();
            st.chinese = query.value(4).toInt();
            st.math = query.value(5).toInt();
             st.english = query.value(5).toInt();
            studentList.push_back(st);


        }
        return studentList;

    }


}

bool student::addStu(stuInfo info)
{
    QSqlQuery query;
    QString sql = QString("insert into student values(null,'%1','%2','%3',%4,%5,%6)")
                      .arg(info.studentNumber)
                      .arg(info.name)
                      .arg(info.classname)
                      .arg(info.chinese)
                      .arg(info.math)
                      .arg(info.english);
    return query.exec(sql);


}

bool student::delStu(int id)
{
    QSqlQuery query;
    QString sql = QString("delete from student where id = %1").arg(id);

    return query.exec(sql);

}

void student::clearStuTable()
{
    QSqlQuery query;
    QString sql = QString("delete from student");
    query.exec(sql);
}

void student::updateStuInfo(stuInfo info)
{

    QSqlQuery query;
    QString sql = QString("update student set studentNumber = '%1', name='%2', classname='%3', chinese=%4, math=%5, english=%6 where id = %7")
                      .arg(info.studentNumber)
                      .arg(info.name)
                      .arg(info.classname)
                      .arg(info.chinese)
                      .arg(info.math)
                      .arg(info.english)
                      .arg(info.id);
    if(query.exec(sql))
    {
        qDebug()<<"ok";
    }
}

student::stuInfo student::getSomeOne(int id)
{
    QSqlQuery query;
    student::stuInfo stu;
    QString sql =  QString("select * from student where id = %1").arg(id);
    if(query.exec(sql))
    {
        while(query.next())
        {
            stu.id = query.value(0).toInt();
            stu.studentNumber = query.value(1).toString();
            stu.name=query.value(2).toString();
            stu.classname= query.value(3).toString();
            stu.chinese = query.value(4).toInt();
            stu.math = query.value(5).toInt();
            stu.english = query.value(6).toInt();
        }



    }
    return stu;

}

QVector<student::userInfo> student::getAllUsers()
{

    QSqlQuery query;
    QString sql = "select * from user";
    student::userInfo ut;
    if(query.exec(sql))
    {
        while(query.next())
        {
            ut.username = query.value(0).toString();
            ut.password = query.value(1).toString();
            ut.auth = query.value(2).toString();
            userList.push_back(ut);
        }

        return userList;
    }

}

bool student::isExit(QString strUserName,QString password)
{
   userInfo ut =  getUser(strUserName);
    if(ut.username==strUserName&&password==ut.password)
        return true;
    return false;
}

student::userInfo student::getUser(QString strUserName)
{
    userInfo ut;
    QSqlQuery query;
    QString sql = QString("select * from user where username = '%1'").arg(strUserName);
    if(query.exec(sql))
    {
        while(query.next())
        {
            ut.username = query.value(0).toString();
            ut.password = query.value(1).toString();
            ut.auth = query.value(2).toString();
        }
    }
    return ut;
}

bool student::updateUser(userInfo info)
{
    QSqlQuery query;
    QString sql = QString("update user set password='%1', auth='%2' where username = '%3'")
                      .arg(info.password)
                      .arg(info.auth)
                      .arg(info.username);

    if(query.exec(sql))
    {
        qDebug()<<"ok";
    }
}

bool student::addUser(userInfo info)
{
    QSqlQuery query;
    QString sql = QString("insert into user values('%1','%2','%3')")
                      .arg(info.username)
                      .arg(info.password)
                      .arg(info.auth);

    return query.exec(sql);
}

bool student::delUser(QString strUserName)
{
    QSqlQuery query;
    QString sql = QString("delete from user where username = '%1'").arg(strUserName);
    return query.exec(sql);

}

student* student::getinstance()
{
    return new student();
}

void student::sqlInit()
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("test");
    db.setHostName("localhost");
    db.setUserName("chen");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"connect success";
    }
}

