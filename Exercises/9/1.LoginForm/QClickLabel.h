#pragma once

#include <QLabel>
#include <QWidget>
#include <Qt>

class QClickLabel : public QLabel
{
	Q_OBJECT

public:
	QClickLabel(QWidget *parent = Q_NULLPTR);
	~QClickLabel();

signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);
};
