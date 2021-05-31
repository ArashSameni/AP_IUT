#include "QClickLabel.h"

QClickLabel::QClickLabel(QWidget *parent)
	: QLabel(parent)
{
}

QClickLabel::~QClickLabel()
{
}

void QClickLabel::mousePressEvent(QMouseEvent* event) {
	emit clicked();
}