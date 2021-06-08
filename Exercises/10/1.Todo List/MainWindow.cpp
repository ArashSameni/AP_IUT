#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Task.h"
#include "TaskDialog.h"
#include "CustomButton.h"
#include "LoginWindow.h"

int countOfDoneTasks(QVector<int> tasks);

MainWindow::MainWindow(QString username)
    :  ui(new Ui::MainWindow),
       user(User::getUser(username))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setFullNameLabel(user.getFullName());

    scrollLayout = new QVBoxLayout();
    ui->scrollContents->setLayout(scrollLayout);

    QVector<int> userTasks = user.getTasks();
    for(int i = 0; i < userTasks.size(); i++)
        addTaskElemets(Task::getTask(userTasks[i]));
    doneCount = countOfDoneTasks(userTasks);
    todosCount = userTasks.size() - doneCount;

    setStatusLabel(todosCount, doneCount);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::addTask(QString taskTitle)
{
    if(!taskTitle.isEmpty())
    {
        Task task(user.getUsername(), taskTitle);
        task.save();
        user.addTask(task.getId());
        addTaskElemets(task);

        todosCount++;
        setStatusLabel(todosCount, doneCount);
    }
}

void MainWindow::setFullNameLabel(QString fullName)
{
    ui->fullNameLabel->setText("Your name: " + fullName);
    ui->fullNameLabel->adjustSize();
}

void MainWindow::setStatusLabel(int todosCount, int doneCount)
{
    ui->statusLabel->setText("Status: " + QString::number(todosCount) + " Todo/" + QString::number(doneCount) + " Done");
    ui->statusLabel->adjustSize();
}

void MainWindow::addTaskElemets(Task task)
{
    QGroupBox* newGroupBox = new QGroupBox();
    newGroupBox->setStyleSheet("QGroupBox{ border-radius: 8px; border: 1px solid white; } * { color: white; }");

    QHBoxLayout* hbl = new QHBoxLayout(newGroupBox);

    CustomCheck* titleLabel = new CustomCheck(task.getId(), task.getTitle());
    if(task.isDone())
    {
        titleLabel->setChecked(true);
        titleLabel->setStyleSheet("QCheckBox{ text-decoration: line-through; }");
    }
    titleLabel->setCursor(Qt::PointingHandCursor);
    titleLabel->setFont(QFont("Lato", 13));
    connect(titleLabel, &QCheckBox::stateChanged, this, &MainWindow::taskStateChanged);
    hbl->addWidget(titleLabel);

    CustomButton* editButton = new CustomButton(task.getId(), "Edit", newGroupBox);
    editButton->setFont(QFont("Lato", 12));
    editButton->setCursor(Qt::PointingHandCursor);
    editButton->setFixedSize(80, 40);
    editButton->setStyleSheet("QPushButton{\n	background-color: #474747;\n	border: 3px solid  rgb(232, 66, 130);\n	border-radius: 8px;\n	color: white;\n}\n\nQPushButton:hover{\n	background-color:  rgb(232, 66, 130);\n}");
    hbl->addWidget(editButton);
    connect(editButton, &CustomButton::clicked, this, &MainWindow::openEditForm);

    CustomButton* removeButton = new CustomButton(task.getId(), "X", newGroupBox);
    editButton->setFont(QFont("Lato", 12));
    removeButton->setCursor(Qt::PointingHandCursor);
    removeButton->setFixedSize(40, 40);
    removeButton->setStyleSheet("QPushButton{\n	background-color: #474747;\n	border: 3px solid rgb(148, 148, 148);\n	border-radius: 8px;\n	color: white;\n}\n\nQPushButton:hover{\n	background-color: rgb(148, 148, 148);\n}");
    hbl->addWidget(removeButton);
    connect(removeButton, &CustomButton::clicked, this, &MainWindow::removeTask);

    newGroupBox->setMinimumHeight(60);
    scrollLayout->addWidget(newGroupBox);

    groupBoxes[task.getId()] = newGroupBox;
    titles[task.getId()] = titleLabel;
}

int countOfDoneTasks(QVector<int> tasks)
{
    int count = 0;
    for(int i = 0; i < tasks.size(); i++)
    {
        Task task = Task::getTask(tasks[i]);
        if(task.isDone())
            count++;
    }
    return count;
}

void MainWindow::on_actionAdd_Task_triggered()
{
    TaskDialog* addTaskDialog = new TaskDialog(this);
    connect(addTaskDialog, SIGNAL(addTask(QString)), this, SLOT(addTask(QString)));
    addTaskDialog->exec();
}

void MainWindow::on_addTaskButton_clicked()
{
    on_actionAdd_Task_triggered();
}

void MainWindow::removeTask()
{
    int taskId = ((CustomButton*)sender())->id;
    Task::remove(taskId);
    user.removeTask(taskId);
    scrollLayout->removeWidget(groupBoxes[taskId]);

    if(titles[taskId]->isChecked())
        doneCount--;
    else
        todosCount--;
    setStatusLabel(todosCount, doneCount);

    delete groupBoxes[taskId];
}

void MainWindow::taskStateChanged(int state)
{
    CustomCheck* checkbox = ((CustomCheck*)sender());
    int taskId = checkbox->id;
    Task task = Task::getTask(taskId);
    if(state)
    {
        checkbox->setStyleSheet("QCheckBox{ text-decoration: line-through; }");
        task.check();

        todosCount--;
        doneCount++;
        setStatusLabel(todosCount, doneCount);
    }
    else
    {
        checkbox->setStyleSheet("");
        task.unCheck();

        todosCount++;
        doneCount--;
        setStatusLabel(todosCount, doneCount);
    }
    task.save();
}

void MainWindow::openEditForm()
{
    int taskId = ((CustomButton*)sender())->id;
    TaskDialog* dialog = new TaskDialog(this, taskId);
    connect(dialog, SIGNAL(editTask(int, QString)), this, SLOT(editTask(int, QString)));
    dialog->exec();
}

void MainWindow::on_actionLogout_triggered()
{
    LoginWindow* login = new LoginWindow();
    login->show();
    this->close();
}

void MainWindow::editTask(int taskId, QString taskTitle)
{
    if(!taskTitle.isEmpty())
    {
        Task task = Task::getTask(taskId);
        task.setTitle(taskTitle);
        task.save();
        titles[taskId]->setText(taskTitle);
    }
}
