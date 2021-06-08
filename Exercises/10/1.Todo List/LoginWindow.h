#pragma once

#include <QWidget>
#include <QLayout>
#include "ui_LoginWindow.h"

class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = Q_NULLPTR);
	~LoginWindow();

private slots:
    void on_signupButton_clicked();

    void on_loginButton_clicked();

private:
	Ui::LoginWindow ui;
};
