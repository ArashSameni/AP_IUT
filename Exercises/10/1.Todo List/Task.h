#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QJsonObject>

class Task
{
    static const QString FILENAME;

    int id = 0;
    QString fUsername;
    QString title;
    bool isFinished = false;

    static QJsonObject getTaskAsJson(int id);

public:
    static int tasksCount;
    static QString fileName(){ return FILENAME; }

    static Task getTask(QJsonObject& obj);
    static Task getTask(int id);

    Task(QString fUsername, QString title);
    void check();
    void unCheck();
    void save();
    static void remove(int id);
    void remove();
    bool isDone(){ return isFinished; }
    int getId() { return id; }
    QString getTitle() { return title; }
    void setTitle(QString title){ this->title = title; }
};

#endif // TASK_H
