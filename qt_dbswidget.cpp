#include "qt_dbswidget.h"
#include <QFont>
#include <QDebug>
DBSWidget::DBSWidget(const Score *_score, QWidget *parent):
    ScoreWidget(parent),dbscore(dynamic_cast<const DouBanScore*>(_score))
{
    title=new QLabel("DouBan Score",parent);



    basescore=new QLabel(QString::number(dbscore->getScore()),parent); //!!! get score by obj
    QFont font("Microsoft YaHei",30,75);
    basescore->setFont(font);

    int starnum=5; //!!
    double rate[5];
    for(int i=0;i<starnum;i++){
        rate[i]=dbscore->getRate(i+1);
        qDebug() << rate[i] ;
    }
    for(int i=5;i>=1;i--){
        starline t;
        t.number=new QLabel(QString::number(i)+" star",parent);
        QImage image(":/yellowBar.jpg");
        image=image.scaled(QSize((rate[i-1])*300,10));
        t.image=new QLabel(parent);
        t.image->setPixmap(QPixmap::fromImage(image));
        starvec.push_back(t);
    }


    glayout=new QGridLayout;
    glayout->addWidget(title,0,0,1,2);
    glayout->addWidget(basescore,0,2,1,3);
    for(int i=0;i<starvec.size();i++){
        glayout->addWidget(starvec[i].number,1+i,0,1,1);
        glayout->addWidget(starvec[i].image,1+i,1,1,4);
    }

    this->setLayout(glayout);
}

void DBSWidget::show(){
    title->show();
    basescore->show();
    for(int i=0;i<starvec.size();i++){
        starvec[i].image->show();
        starvec[i].number->show();
    }
}

void DBSWidget::hide(){
    title->hide();
    basescore->hide();
    for(int i=0;i<starvec.size();i++){
        starvec[i].image->hide();
        starvec[i].number->hide();
    }
}
