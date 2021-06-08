#ifndef CUSTOMCHECK_H
#define CUSTOMCHECK_H

#include <QCheckBox>

class CustomCheck : public QCheckBox
{
public:
    int id;
    CustomCheck(int id, const QString &text, QWidget *parent = nullptr);
};

#endif // CUSTOMCHECK_H
