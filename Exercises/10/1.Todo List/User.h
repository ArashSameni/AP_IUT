#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include "Task.h"

class User
{
    static const QString FILENAME;

    QString fullName;
    QString username;
    QString password;
    QVector<int> tasks;

    static QString encrypt(QString password);

    static QJsonObject getUserAsJson(QString& username);

public:
    User(QString username,
         QString password,
         QString fullName = "");

    QString getFullName() { return fullName; }
    QString getUsername(){ return username; }
    QVector<int> getTasks() { return tasks; }
    static QString fileName(){ return FILENAME; }

    static bool authenticate(QString username,
                      QString password);

    static User getUser(QJsonObject& username);
    static User getUser(QString& username);
    static bool exists(QString& username);
    void addTask(int taskId);
    void removeTask(int taskId);

    void save();
};

#endif // USER_H
