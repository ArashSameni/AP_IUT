#include <QCryptographicHash>
#include <QJsonArray>
#include <QJsonValue>
#include "User.h"
#include "file.h"

const QString User::FILENAME = "users.json";

QString User::encrypt(QString password)
{
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
}

User::User(QString username, QString password, QString fullName)
{
    this->fullName = fullName;
    this->username = username;
    this->password = encrypt(password);
}

bool User::authenticate(QString username, QString password)
{
    username = username.toLower();
    if(!exists(username))
        return false;

    User user = getUser(username);
    return user.password == encrypt(password);
}

void User::save()
{
    QJsonObject userObj;
    userObj["fullName"] = this->fullName;
    userObj["username"] = this->username.toLower();
    userObj["password"] = this->password;

    QJsonArray tasksArray;
    for (int i = 0; i < this->tasks.size(); i++)
        tasksArray.append(QJsonValue(this->tasks[i]));
    userObj["tasks"] = tasksArray;

    saveObject(FILENAME, this->username.toLower(), userObj);
}

QJsonObject User::getUserAsJson(QString& username)
{
    return getObject(FILENAME, username.toLower());
}

User User::getUser(QJsonObject& userObj)
{
    User tempUser(userObj["username"].toString(),
        "",
        userObj["fullName"].toString());

    tempUser.password = userObj["password"].toString();

    QJsonArray tasksArray = userObj["tasks"].toArray();
    foreach(QJsonValue x, tasksArray)
        tempUser.tasks.push_back(x.toInt());

    return tempUser;
}

User User::getUser(QString& username)
{
    QJsonObject obj = getUserAsJson(username);
    return getUser(obj);
}

bool User::exists(QString &username)
{
    return existsObject(FILENAME, username.toLower());
}

void User::addTask(int taskId)
{
    tasks.push_back(taskId);
    save();
}

void User::removeTask(int taskId)
{
    tasks.removeAll(taskId);
    save();
}
