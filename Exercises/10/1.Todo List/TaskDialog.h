#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDialog>
#include "Task.h"

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr, int taskId = 0);
    ~TaskDialog();

signals:
    void addTask(QString);
    void editTask(int, QString);

private slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();

private:
    int taskId = 0;
    Ui::TaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
