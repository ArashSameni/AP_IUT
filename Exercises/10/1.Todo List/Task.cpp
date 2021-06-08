#include "Task.h"
#include "file.h"
#include <QDebug>

const QString Task::FILENAME = "tasks.json";
int Task::tasksCount = 0;

QJsonObject Task::getTaskAsJson(int id)
{
    return getObject(FILENAME, QString::number(id));
}

Task Task::getTask(QJsonObject &obj)
{
    Task task(obj["fUsername"].toString(),
            obj["title"].toString());
    task.id = obj["id"].toInt();
    task.isFinished = obj["isFinished"].toBool();

    return task;
}

Task Task::getTask(int id)
{
    QJsonObject obj = getTaskAsJson(id);
    return getTask(obj);
}

Task::Task(QString fUsername, QString title)
{
    this->fUsername = fUsername;
    this->title = title;
}

void Task::check()
{
    isFinished = true;
}

void Task::unCheck()
{
    isFinished = false;
}

void Task::save()
{
    if(!id)
        id = ++tasksCount;

    QJsonObject obj;
    obj["id"] = id;
    obj["fUsername"] = fUsername;
    obj["title"] = title;
    obj["isFinished"] = isFinished;

    saveObject(FILENAME, QString::number(id), obj);
}

void Task::remove(int id)
{
    removeObject(FILENAME, QString::number(id));
}

void Task::remove()
{
    removeObject(FILENAME, QString::number(id));
}
