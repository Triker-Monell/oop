#include "qt_levelsearch.h"
#include "qt_config.h"
#include "qt_movie.h"
#include "qt_person.h"
#include <QPalette>
LevelSearch::LevelSearch(QWidget *_central, QWidget* parent):Level(_central,parent)
{
    name=new QPushButton(parent);
    //get search_name by config
    name->setText(Config::instance().getSearchTitle(parent));
    personname=new QPushButton("Person",parent);

    //set checkable
    name->setCheckable(true);
    name->setChecked(true); //default:name is checked
    personname->setCheckable(true);

    searchline=new QLineEdit(parent);
    confirmbtn=new QPushButton("Search",parent);
    tips=new QLabel(parent);
    tips->setAlignment(Qt::AlignLeft);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    tips->setPalette(pa);

    //connect!!
    connect(name,SIGNAL(clicked(bool)),this,SLOT(name_clicked()));
    connect(personname,SIGNAL(clicked(bool)),this,SLOT(person_clicked()));
    connect(confirmbtn,SIGNAL(clicked(bool)),this,SLOT(search_clicked()));
    //...so on


    //
}

void LevelSearch::pushlayout(){
    //size and position control
    /*
    name->setGeometry(100,50,100,20);
    searchline->setGeometry(100,100,200,50);
    */
    vlayout=new QVBoxLayout();
    hlayout=new QHBoxLayout();
    hlayout->addWidget(name);
    hlayout->addWidget(personname);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(searchline);
    vlayout->addWidget(confirmbtn);
    vlayout->addWidget(tips);
    if(central->layout()!=nullptr){
        delete central->layout();
    }
    central->setLayout(vlayout);

    //set minsize
    name->setMinimumSize(100,100);
    name->setMaximumSize(200,150);
    personname->setMinimumSize(100,100);
    personname->setMaximumSize(200,150);
    searchline->setMinimumSize(300,50);
    confirmbtn->setMinimumSize(200,50);
    tips->setMinimumSize(100,50);
    tips->setMaximumSize(100,50);
}

void LevelSearch::show(){
    pushlayout();
    name->show();
    personname->show();
    searchline->show();
    confirmbtn->show();
    tips->show();
}

void LevelSearch::hide(){
    name->hide();
    personname->hide();
    searchline->hide();
    confirmbtn->hide();

    tips->setText("");
    tips->hide();
}

void LevelSearch::name_clicked(){
    name->setChecked(true);
    personname->setChecked(false);
}

void LevelSearch::person_clicked(){
    personname->setChecked(true);
    name->setChecked(false);
}

void LevelSearch::search_clicked(){
    if(searchline->text()==""){
        qDebug() << "cant search null";
        tips->setText("Empty input!!");
        return;
    }
    //other error control

    QString _name=searchline->text();

    Details* detail;
    if(personname->isChecked()){
        detail=new Person(_name,central,window);
        //person need obj data
    }
    else
        detail=Config::instance().getDetails(_name,central,window);

    this->hide();
    detail->show();

    passLevel(detail);
}

void LevelSearch::name_change(Action *ac){
    QString str=ac->text();
    name->setText(str);
}

LevelSearch::~LevelSearch(){
    //??? it will abend without note
    /*
    delete name;
    delete personname;
    delete searchline;
    delete confirmbtn;
    */
}
