#include "User.h"
#include <QCryptographicHash>

void User::setPassword(QString _password)
{
	QByteArray byteArr = QCryptographicHash::hash(_password.toUtf8(), QCryptographicHash::Md5);
	password = byteArr;
}
