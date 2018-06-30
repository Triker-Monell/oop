#include "qt_imdbswidget.h"

IMDBSWidget::IMDBSWidget(QWidget *parent):ScoreWidget(parent)
{
    imagelabel=new QLabel(parent);
    QImage image(":/IMDBstar.png");
    image=image.scaled(QSize(50,50));
    imagelabel->setPixmap(QPixmap::fromImage(image));

    //obj!!

    scorelabel=new QLabel("5.5",parent);
    maxscorelabel=new QLabel("/10",parent);
    QFont font_big("Microsoft YaHei",30,75);
    scorelabel->setFont(font_big);
    QFont font_small("Microsoft YaHei",15,40);
    maxscorelabel->setFont(font_small);

    glayout=new QGridLayout();

    glayout->addWidget(imagelabel,0,0,2,2);
    glayout->addWidget(scorelabel,0,2,2,2);
    glayout->addWidget(maxscorelabel,0,4,2,2);
    this->setLayout(glayout);
}


void IMDBSWidget::show(){
    imagelabel->show();
    scorelabel->show();
    maxscorelabel->show();
}

void IMDBSWidget::hide(){
    imagelabel->hide();
    scorelabel->hide();
    maxscorelabel->hide();
}
