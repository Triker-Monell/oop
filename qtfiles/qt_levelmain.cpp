#include "qt_levelmain.h"
#include "qt_mainwindow.h"
#include "qt_levelrank.h"

LevelMain::LevelMain(QWidget *_central, QWidget *parent):Level(_central,parent)
{
    rankbtn=new QPushButton("Rank",parent);
    searchbtn=new QPushButton("Search by Name",parent);

    //connect
    connect(rankbtn,SIGNAL(clicked(bool)),this,SLOT(rankbtn_clicked()));
    connect(searchbtn,SIGNAL(clicked(bool)),this,SLOT(searchbtn_clicked()));



}

void LevelMain::pushlayout(){
    //size and position control!
    layout=new QVBoxLayout;
    layout->addWidget(rankbtn);
    layout->addWidget(searchbtn);

    if(central->layout()!=nullptr){
        qDebug()<<"has ptr";
        delete central->layout();
        if(central->layout()!=nullptr){
            qDebug() << "has ptr ???";
        }
    }

    central->setLayout(layout);

    if(central->layout()!=nullptr){
        qDebug() << "has ptr again";
    }

    rankbtn->setMinimumSize(200,100);
    searchbtn->setMinimumSize(200,100);
}

void LevelMain::show(){
    pushlayout();
    rankbtn->show();
    searchbtn->show();
}

void LevelMain::hide(){
    rankbtn->hide();
    searchbtn->hide();
}

void LevelMain::rankbtn_clicked(){
    LevelRank* levelrank=new LevelRank(central,window);
    this->hide();
    levelrank->show();

    passLevel(levelrank);
}

void LevelMain::searchbtn_clicked(){
    LevelSearch* levelsearch=new LevelSearch(central,window);
    this->hide();
    levelsearch->show();

    passLevel(levelsearch);

}
LevelMain::~LevelMain(){
    //
}

