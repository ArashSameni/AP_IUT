#include "CustomButton.h"

CustomButton::CustomButton(int id, const QString& text, QWidget* parent)
    : QPushButton(text, parent)
{
    this->id = id;
}
