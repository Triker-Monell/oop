#include "qt_levelrank.h"
#include <fstream>
#include "qt_mainwindow.h"
#include "Catcher/allCatcher.h"
#include "qt_level.h"
#include "BaseData/path.h"
LevelRank::LevelRank(QWidget *_central, QWidget *parent):Level(_central,parent)
{/*****  old
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


    //debug!!
    hide();
    textedit=new QTextEdit(parent);
    std::ifstream in("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/test.txt");
    std::string tmp,str;
    while(std::getline(in,tmp)){
        str+=tmp+"\n";
    }
    textedit->setText(QString::fromStdString(str));
    textedit->setReadOnly(true);
    glayout->addWidget(textedit,10,10,10,10);

    */


    int num=MainWindow::webnum;
    for(int i=0;i<num;i++){
        QPushButton* btn=new QPushButton(parent);
        btns.push_back(btn);

        QLabel* label=new QLabel(parent);
        labels.push_back(label);
    }

    tips=new QLabel("toplist爬取时间较长，请耐心",parent);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    tips->setPalette(pa);

    connect(btns[MainWindow::DouBan],SIGNAL(clicked()),this,SLOT(Douban_triggered()));
    btns[MainWindow::DouBan]->setText("Douban_toplist");
    connect(btns[MainWindow::IMDB],SIGNAL(clicked()),this,SLOT(IMDB_triggered()));
    btns[MainWindow::IMDB]->setText("IMDB_toplist");
    connect(btns[MainWindow::RottenTomatoes],SIGNAL(clicked()),this,SLOT(RT_triggered()));
    btns[MainWindow::RottenTomatoes]->setText("RottenTomatoes_toplist");

    vlayout=new QVBoxLayout();
    pushlayout();
    show();

}

void LevelRank::pushlayout(){
    vlayout->addWidget(btns[MainWindow::DouBan]);
    vlayout->addWidget(labels[MainWindow::DouBan]);
    vlayout->addWidget(btns[MainWindow::IMDB]);
    vlayout->addWidget(labels[MainWindow::IMDB]);
    vlayout->addWidget(btns[MainWindow::RottenTomatoes]);
    vlayout->addWidget(labels[MainWindow::RottenTomatoes]);

    vlayout->addWidget(tips);

    if(central->layout()!=nullptr){
        qDebug()<< "has laytout";
        delete central->layout();
    }


    central->setLayout(vlayout);
}


void LevelRank::Douban_triggered(){
    Douban_by_toplist douban;
    douban.MakeCatcher();
    std::string text="see data in " +PATH+"Douban_by_toplists";
    labels[MainWindow::DouBan]->setText(QString::fromStdString(text));
}

void LevelRank::RT_triggered(){
    RottenTomatoes_by_toplist rt;
    rt.MakeCatcher();
    std::string text="see data in " +PATH+"RottenTomatoes_by_toplists";
    labels[MainWindow::RottenTomatoes]->setText(QString::fromStdString(text));
}

void LevelRank::IMDB_triggered(){
    IMDB_by_toplist imdb;
    imdb.MakeCatcher();
    std::string text="see data in " +PATH+"IMDB_by_toplists";
    labels[MainWindow::IMDB]->setText(QString::fromStdString(text));

}

void LevelRank::show(){
    for(int i=0;i<btns.size();i++){
        btns[i]->show();
    }
    for(int i=0;i<labels.size();i++){
        labels[i]->show();
    }
    tips->show();
}


void LevelRank::hide(){
    for(int i=0;i<btns.size();i++){
        btns[i]->hide();
    }
    for(int i=0;i<labels.size();i++){
        labels[i]->hide();
    }
    tips->hide();
}

LevelRank::~LevelRank(){

}



/******  old
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
    delete scorebtn;
    delete datebtn;
    delete typecombobox;
    delete typelabel;
    delete list;
    delete imagelabel;

    //can't delete
}
*/
