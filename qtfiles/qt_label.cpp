#include "qt_label.h"

Label::Label(QWidget *parent):QLabel(parent)
{

}

void Label::mousePressEvent(QMouseEvent *ev){
    emit triggered(this->text());
}

void Label::mouseMoveEvent(QMouseEvent *ev){

}
