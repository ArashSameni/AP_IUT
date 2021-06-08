#include "SignupWindow.h"
#include <QMessageBox>
#include "User.h"

SignupWindow::SignupWindow(QWidget *parent)
{
	ui.setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    this->parent = parent;
}

SignupWindow::~SignupWindow()
{
}

void SignupWindow::closeEvent(QCloseEvent *event)
{
    parent->show();
}

void SignupWindow::on_signupButton_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setStyleSheet("color: white;");

    if(ui.fullNameLineEdit->text().isEmpty() ||
            ui.usernameLineEdit->text().isEmpty() ||
            ui.passwordLineEdit->text().isEmpty())
    {
        msg->setText("Please fill the form.");
        msg->show();
        return;
    }
    QString username = ui.usernameLineEdit->text();

    if(User::exists(username))
    {
        msg->setText("Username already exists.");
        msg->show();
        return;
    }

    User newUser(ui.usernameLineEdit->text(),
                 ui.passwordLineEdit->text(),
                 ui.fullNameLineEdit->text());
    newUser.save();
    msg->setText("Your account has been created successfully.");
    msg->show();
    this->close();
}
