#include "SignUpForm.h"
#include <QMessageBox>

SignUpForm::SignUpForm(QVector<User>& users, QWidget* parent)
	: QWidget(parent), users(users)
{
	setWindowTitle("SignUp Form");
	SignUpGroupBox.setTitle("SignUp Form");
	txt_Password.setEchoMode(QLineEdit::Password);
	cmb_Gender.addItem("Male");
	cmb_Gender.addItem("Female");
	cmb_Gender.setCurrentIndex(0);
	spin_Age.setMinimum(5);
	spin_Age.setMaximum(150);
	
	FormLayout.addRow("FullName:", &txt_FullName);
	FormLayout.addRow("Username:", &txt_Username);
	FormLayout.addRow("Password:", &txt_Password);
	FormLayout.addRow("Email:", &txt_Email);
	FormLayout.addRow("Age:", &spin_Age);
	FormLayout.addRow("Gender:", &cmb_Gender);
	btn_SignUp.setText("SignUp");
	FormLayout.addRow(&btn_SignUp);

	lbl_Login.setText("Login");
	lbl_Login.setCursor(Qt::PointingHandCursor);
	lbl_Login.setStyleSheet("QLabel { color : blue; font-size: 15px;}");
	SignUpGroupBox.setLayout(&FormLayout);
	
	MainLayout.addWidget(&SignUpGroupBox);
	MainLayout.addWidget(&lbl_Login);
	setLayout(&MainLayout);

	connect(&lbl_Login, &QClickLabel::clicked, this, &SignUpForm::lbl_Login_Clicked);
	connect(&btn_SignUp, &QPushButton::clicked, this, &SignUpForm::btn_SignUp_Clicked);
}


void SignUpForm::lbl_Login_Clicked()
{
	LoginForm* lf = new LoginForm(users);
	lf->show();
	close();
}

void SignUpForm::btn_SignUp_Clicked()
{
	if(txt_FullName.text().isEmpty() || txt_Email.text().isEmpty() || txt_Username.text().isEmpty() || txt_Password.text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Error");
		msgBox.setText("Please fill the form.");
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return;
	}

	User newUser(txt_FullName.text(),
		txt_Username.text(),
		txt_Password.text(),
		txt_Email.text(),
		spin_Age.value());

	if (cmb_Gender.currentText() == "Female")
		newUser.setGender('f');

	users.push_back(newUser);

	QMessageBox msgBox;
	msgBox.setWindowTitle("Success");
	msgBox.setText("Your account has been successfully created.");
	msgBox.setIcon(QMessageBox::Information);
	int ret = msgBox.exec();

	LoginForm* lf = new LoginForm(users, txt_Username.text());
	lf->show();
	close();
}