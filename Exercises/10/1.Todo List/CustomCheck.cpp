#include "CustomCheck.h"


CustomCheck::CustomCheck(int id, const QString &text, QWidget *parent) : QCheckBox(text, parent)
{
    this->id = id;
}
