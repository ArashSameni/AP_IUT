#pragma once
#include <QString>

class User
{
	QString fullName;
	QString username;
	QString password;
	QString email;
	int age;
	unsigned char gender;

public:
	User(QString _fullName = "",
		QString _username = "",
		QString _password = "",
		QString _email = "",
		int _age = 5,
		unsigned char _gender = 'm')
	{
		setFullName(_fullName);
		setUsername(_username);
		setPassword(_password);
		setEmail(_email);
		setAge(_age);
		setGender(_gender);
	}

	QString getFullName() { return fullName; }
	QString getUsername() { return username; }
	QString getPassword() { return password; }
	QString getEmail() { return email; }
	int getAge() { return age; }
	unsigned char getGender() { return gender; }

	void setFullName(QString _fullName) { fullName = _fullName; }
	void setUsername(QString _username) { username = _username; }
	void setPassword(QString _password);
	void setEmail(QString _email) { email = _email; }
	void setAge(int _age) { age = _age; }
	void setGender(unsigned char _gender) { gender = _gender; }

};

