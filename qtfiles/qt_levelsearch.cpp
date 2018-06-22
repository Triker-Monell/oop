#include "qt_levelsearch.h"
#include "qt_config.h"
#include "qt_movie.h"
#include "qt_person.h"
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
    if(central->layout()!=nullptr){
        delete central->layout();
    }
    central->setLayout(vlayout);

    //set minsize
    name->setMinimumSize(100,100);
    personname->setMinimumSize(100,100);
    searchline->setMinimumSize(300,100);
    confirmbtn->setMinimumSize(200,50);

}

void LevelSearch::show(){
    pushlayout();
    name->show();
    personname->show();
    searchline->show();
    confirmbtn->show();
}

void LevelSearch::hide(){
    name->hide();
    personname->hide();
    searchline->hide();
    confirmbtn->hide();
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
    //other error control

    Details* detail;
    if(personname->isChecked()){
        detail=new Person(central,window);
        //person need obj data
    }
    else
        detail=Config::instance().getDetails(central,window);

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
