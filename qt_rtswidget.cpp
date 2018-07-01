#include "qt_rtswidget.h"

RTSWidget::RTSWidget(const Score* _score,QWidget* parent):ScoreWidget(parent),score(dynamic_cast<const RottenTomatoesScore*>(_score))
{
    //!!obj provide all data
    freshlabel=new QLabel(QString::number(100*score->getFresh())+"%",parent);
    QFont font("Microsoft YaHei",30,75);
    freshlabel->setFont(font);

    ratinglabel=new QLabel(QString::number(score->getAverageRating())+"/10",parent);
    imagelabel=new QLabel(parent);

    if(100*score->getFresh()>80){
        QImage image(":/fresh.png");
        imagelabel->resize(image.width(),image.height());
        imagelabel->setPixmap(QPixmap::fromImage(image));
    }
    else{
        QImage image(":/rotten.png");
        imagelabel->resize(image.width(),image.height());
        imagelabel->setPixmap(QPixmap::fromImage(image));
    }


    glayout=new QGridLayout();
    glayout->addWidget(imagelabel,0,0,2,2);
    glayout->addWidget(freshlabel,1,0,1,1);
    glayout->addWidget(ratinglabel,1,1,1,1);

    this->setLayout(glayout);
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
