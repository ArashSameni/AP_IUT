#pragma once

#include <qboxlayout.h>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QSpinBox>
#include <QComboBox>
#include "LoginForm.h"
#include "QClickLabel.h"
#include "User.h"

class SignUpForm : public QWidget
{
	Q_OBJECT

public:
	SignUpForm(QVector<User>& users, QWidget* parent = Q_NULLPTR);

private slots:
	void lbl_Login_Clicked();
	void btn_SignUp_Clicked();

private:
	QVector<User>& users;
	QVBoxLayout MainLayout;

	QGroupBox SignUpGroupBox;
	QFormLayout FormLayout;

	QLineEdit txt_FullName;
	QLineEdit txt_Username;
	QLineEdit txt_Password;
	QLineEdit txt_Email;
	QSpinBox spin_Age;
	QComboBox cmb_Gender;
	
	QPushButton btn_SignUp;
	QClickLabel lbl_Login;
};
