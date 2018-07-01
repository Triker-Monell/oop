#include "qt_label.h"

Label::Label(QWidget *parent, bool _isPeople):QLabel(parent),isPeople(_isPeople)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
}

void Label::mousePressEvent(QMouseEvent *ev){
    emit triggered(this->text(),isPeople);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::darkYellow);
    this->setPalette(pa);
}

void Label::mouseReleaseEvent(QMouseEvent *ev){
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    this->setPalette(pa);
}
