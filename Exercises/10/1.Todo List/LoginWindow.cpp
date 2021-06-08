#include "LoginWindow.h"
#include "SignupWindow.h"
#include "User.h"
#include "MainWindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
	: QWidget(parent)
{
    ui.setupUi(this);
	setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    ui.usernameLineEdit->setFocus();
}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::on_signupButton_clicked()
{
    SignupWindow* signupWindow = new SignupWindow(this);
    this->hide();
    signupWindow->show();
}

void LoginWindow::on_loginButton_clicked()
{
    if(User::authenticate(ui.usernameLineEdit->text(), ui.passwordLineEdit->text()))
    {
        MainWindow *mainWindow = new MainWindow(ui.usernameLineEdit->text());
        mainWindow->show();
        this->close();
    }
    else
    {
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Username or password is incorrect.");
        msg->setStyleSheet("color: white;");
        msg->show();
    }
}
