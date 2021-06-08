#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include "MainWindow.h"

class CustomButton : public QPushButton
{
public:
    int id;
    CustomButton(int id, const QString& text, QWidget* parent = nullptr);
};

#endif // CUSTOMBUTTON_H
