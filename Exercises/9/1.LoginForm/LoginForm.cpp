#include "LoginForm.h"

#include <QCryptographicHash>
#include <QMessageBox>

LoginForm::LoginForm(QVector<User>& users, QString username, QWidget* parent)
	: QWidget(parent), users(users)
{
	setWindowTitle("Login Form");

	if (!username.isEmpty())
		txt_Username.setText(username);
	LoginGroupBox.setTitle("Login Form");
	FormLayout.addRow("Username:", &txt_Username);
	txt_Password.setEchoMode(QLineEdit::Password);
	FormLayout.addRow("Password:", &txt_Password);
	btn_Login.setText("Login");
	FormLayout.addRow(&btn_Login);

	lbl_SignUp.setText("SignUp");
	lbl_SignUp.setCursor(Qt::PointingHandCursor);
	lbl_SignUp.setStyleSheet("QLabel { color : blue; font-size: 15px;}");
	LoginGroupBox.setLayout(&FormLayout);
	MainLayout.addWidget(&LoginGroupBox);
	MainLayout.addWidget(&lbl_SignUp);
	setLayout(&MainLayout);

	connect(&lbl_SignUp, &QClickLabel::clicked, this, &LoginForm::lbl_SignUp_Clicked);
	connect(&btn_Login, &QPushButton::clicked, this, &LoginForm::btn_Login_Clicked);
}

void LoginForm::lbl_SignUp_Clicked()
{
	SignUpForm* suf = new SignUpForm(users);
	suf->show();
	close();
}

void LoginForm::btn_Login_Clicked()
{
	if (txt_Username.text().isEmpty() || txt_Password.text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Error");
		msgBox.setText("Please fill the form.");
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return;
	}

	bool loggedIn = false;
	User selectedUser;
	QString HashedPassword = QCryptographicHash::hash(txt_Password.text().toUtf8(), QCryptographicHash::Md5);
	for (int i = 0; i < users.count(); i++)
	{
		if (users[i].getUsername().toLower() == txt_Username.text().toLower() && users[i].getPassword() == HashedPassword)
		{
			selectedUser = users[i];
			loggedIn = true;
			break;
		}
	}

	if (!loggedIn)
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Error");
		msgBox.setText("Username or password is incorrect.");
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return;
	}

	QString text = "Fullname: " + selectedUser.getFullName() + "\n";
	text += "Email: " + selectedUser.getEmail() + "\n";
	text += "Age: " + QString::number(selectedUser.getAge()) + "\n";
	if (selectedUser.getGender() == 'm')
		text += "Gender: Male";
	else
		text += "Gender: Female";

	QMessageBox msgBox;
	msgBox.setWindowTitle("Success");
	msgBox.setText(text);
	msgBox.setIcon(QMessageBox::Information);
	int ret = msgBox.exec();
}