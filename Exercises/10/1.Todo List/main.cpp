#include "LoginWindow.h"
#include "file.h"
#include "Task.h"
#include "User.h"
#include <QApplication>
#include "MainWindow.h"

void Initialize();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Initialize();

    LoginWindow w;
    w.show();

    return a.exec();
}

void Initialize()
{
    createFileIfNotExist(User::fileName());
    createFileIfNotExist(Task::fileName());
    Task::tasksCount = countOfObjects(Task::fileName());
}
