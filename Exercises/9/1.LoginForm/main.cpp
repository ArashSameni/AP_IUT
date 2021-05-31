#include "LoginForm.h"
#include <QtWidgets/QApplication>
#include "User.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<User> users;
    LoginForm w(users);
    w.show();
    return a.exec();
}
