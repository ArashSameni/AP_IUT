#pragma once

#include <QtWidgets/QMainWindow>
#include <QLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include "QClickLabel.h"
#include "User.h"
#include "SignUpForm.h"

class LoginForm : public QWidget
{
	Q_OBJECT

public:
	LoginForm(QVector<User>& users, QString username = "", QWidget* parent = Q_NULLPTR);

private slots:
	void lbl_SignUp_Clicked();
	void btn_Login_Clicked();

private:
	QVector<User>& users;
	
	QVBoxLayout MainLayout;

	QGroupBox LoginGroupBox;
	QFormLayout FormLayout;

	QLineEdit txt_Username;
	QLineEdit txt_Password;

	QPushButton btn_Login;
	QClickLabel lbl_SignUp;
};
