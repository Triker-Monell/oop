#include "qt_rtswidget.h"

RTSWidget::RTSWidget(QWidget *parent):ScoreWidget(parent)
{
    //!!obj provide all data
    freshlabel=new QLabel("86%",parent);
    ratinglabel=new QLabel("7.7/10",parent);
    imagelabel=new QLabel(parent);
    //image is dependent on the fresh
    //......

    glayout=new QGridLayout();

}

void RTSWidget::show(){
    freshlabel->show();
    ratinglabel->show();
    imagelabel->show();
}

void RTSWidget::hide(){
    freshlabel->hide();
    ratinglabel->hide();
    imagelabel->hide();
}
