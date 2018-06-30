#include "qt_label.h"

Label::Label(QWidget *parent):QLabel(parent)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
}

void Label::mousePressEvent(QMouseEvent *ev){
    emit triggered(this->text());
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::darkYellow);
    this->setPalette(pa);
}

void Label::mouseReleaseEvent(QMouseEvent *ev){
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    this->setPalette(pa);
}
