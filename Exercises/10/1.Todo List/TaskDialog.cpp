#include "TaskDialog.h"
#include "ui_TaskDialog.h"

TaskDialog::TaskDialog(QWidget *parent, int taskId) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);

    this->taskId = taskId;
    if(taskId)
    {
        setWindowTitle("Edit Task");
        ui->titleLineEdit->setText(Task::getTask(taskId).getTitle());
    }
    else
        setWindowTitle("Add Task");

    ui->titleLineEdit->setFocus();
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_cancelButton_clicked()
{
    this->close();
}

void TaskDialog::on_okButton_clicked()
{
    if(taskId)
        emit editTask(taskId, ui->titleLineEdit->text());
    else
        emit addTask(ui->titleLineEdit->text());
    this->close();
}
