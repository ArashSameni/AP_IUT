#pragma once

#include <QWidget>
#include <QCloseEvent>
#include "ui_SignupWindow.h"

class SignupWindow : public QWidget
{
	Q_OBJECT

public:
	SignupWindow(QWidget *parent = Q_NULLPTR);
	~SignupWindow();
    void closeEvent(QCloseEvent *event);

private slots:

    void on_signupButton_clicked();

private:
	Ui::SignupWindow ui;
    QWidget* parent;
};
