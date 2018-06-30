#include "qt_levelrank.h"

LevelRank::LevelRank(QWidget *_central, QWidget *parent):Level(_central,parent)
{
    scorebtn=new QPushButton("Score",parent);
    datebtn=new QPushButton("Date",parent);
    list=new QListWidget(parent);
    typecombobox=new QComboBox(parent);
    typelabel=new QLabel("Type",parent);

    //imagelabel!
    QImage image(":/test.jpg");
    imagelabel=new QLabel(window);
    imagelabel->setPixmap(QPixmap::fromImage(image));
    imagelabel->resize(image.width(),image.height());

    //set and connect
    scorebtn->setCheckable(true);
    datebtn->setCheckable(true);
    connect(scorebtn,SIGNAL(clicked(bool)),this,SLOT(changelist()));
    connect(datebtn,SIGNAL(clicked(bool)),this,SLOT(changelist()));
    connect(typecombobox,SIGNAL(currentIndexChanged(int)),this,SLOT(changelist()));

    //object initial

    //size and position control
    pushlayout();

    //add items in list
    changelist();

    //imageset
}

void LevelRank::changelist(){
    //modify object

    //change the list

    //change the image (the first item's image)


    //test
    for(int i=0;i<6;i++){
        QString str="movie_num "+QString::number(i);
        list->addItem(new QListWidgetItem(str));
    }
}

void LevelRank::changeimage(QListWidgetItem *item){
    //change and show

}

void LevelRank::pushlayout(){ //size and position control
    glayout=new QGridLayout;

    glayout->addWidget(scorebtn,0,0,1,2);
    glayout->addWidget(datebtn,0,2,1,2);
    glayout->addWidget(typelabel,0,8,1,2);
    glayout->addWidget(typecombobox,0,9,1,2);
    glayout->addWidget(list,1,0,7,6);
    glayout->addWidget(imagelabel,1,7,7,4);

    if(central->layout()!=nullptr){
        delete central->layout();
    }
    central->setLayout(glayout);
}


void LevelRank::doubleclicked(QListWidgetItem *item){
    //catcher by the name
}

void LevelRank::show(){
    scorebtn->show();
    datebtn->show();
    typecombobox->show();
    typelabel->show();
    list->show();
    imagelabel->show(); //!!!
}

void LevelRank::hide(){
    scorebtn->hide();
    datebtn->hide();
    typecombobox->hide();
    typelabel->hide();
    list->hide();
    imagelabel->hide();
}

LevelRank::~LevelRank(){
    /*
    delete scorebtn;
    delete datebtn;
    delete typecombobox;
    delete typelabel;
    delete list;
    delete imagelabel;
    */
    //can't delete
}
