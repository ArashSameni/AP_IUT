#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QGroupBox>
#include <QHash>
#include "CustomCheck.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString username);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void addTask(QString taskTitle);
    void on_actionAdd_Task_triggered();
    void on_addTaskButton_clicked();
    void removeTask();
    void taskStateChanged(int state);
    void openEditForm();
    void on_actionLogout_triggered();
    void editTask(int taskId, QString taskTitle);

private:
    int todosCount = 0;
    int doneCount = 0;

    Ui::MainWindow *ui;
    QVBoxLayout* scrollLayout;
    User user;
    QHash<int, QGroupBox*> groupBoxes;
    QHash<int, CustomCheck*> titles;

    void setFullNameLabel(QString fullName);
    void setStatusLabel(int todosCount, int doneCount);
    void addTaskElemets(Task task);
};
#endif // MAINWINDOW_H
