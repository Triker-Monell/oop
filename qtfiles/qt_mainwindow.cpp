#include "qt_mainwindow.h"
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* widget=new QWidget;
    this->setCentralWidget(widget);

    setWindowTitle("Information Collection Sys");
    toolbar=addToolBar("Tool");
    statusbar=statusBar();

    //QAction
    //image!!
    initAction();
    initMenu();

    //size and position control
    this->resize(400,300);

    //levelmain
    LevelMain* levelmain=new LevelMain(widget,this);
    addLevel(levelmain);
    levelmain->show();

}

//TODO images connect
void MainWindow::initTarget(){
    webs[DouBan]=new Action(QIcon(":/DouBan.ico"),tr("DouBan"),this);
    webs[RottenTomatoes]=new Action(QIcon(":/RottenTomatoes.ico"),tr("RottenTomatoes"),this);
    webs[IMDB]=new Action(QIcon(":/IMDB.ico"),tr("IMDB"),this);
    for(int i=0;i<webnum;i++){
        webs[i]->setCheckable(true);
        connect(webs[i],SIGNAL(actrigered(Action*)),this,SLOT(on_action(Action*)));
    }

    objs[Movie]=new Action(tr("Movie"),this);
    objs[Tv]=new Action(tr("Tv"),this);
    for(int i=0;i<objnum;i++){
        objs[i]->setCheckable(true);
        connect(objs[i],SIGNAL(actrigered(Action*)),this,SLOT(on_action(Action*)));
    }


    //connect mode!!
    connect(searchac,SIGNAL(triggered(bool)),this,SLOT(searchac_action()));


    //set default
    webindex=DouBan;//DouBan
    webs[DouBan]->setChecked(true);
    objindex=Movie;//Movie
    objs[Movie]->setChecked(true);
}

//TODO images
void MainWindow::initAction(){
    //image!!!
    //startac=new Action(tr("%Start"),this);
    back2mainac=new Action(tr("Back to Main"),this);
    back2mainac->setStatusTip(tr("back to the main level"));
    toolbar->addAction(back2mainac);
    statusbar->addAction(back2mainac);
    connect(back2mainac,SIGNAL(triggered(bool)),this,SLOT(back2m()));

    back2upperac=new Action(tr("&Back to UpperLevel"),this);
    back2upperac->setStatusTip(tr("back to upper level"));
    toolbar->addAction(back2upperac);
    statusbar->addAction(back2upperac);
    connect(back2upperac,SIGNAL(triggered(bool)),this,SLOT(back2u()));

    rankac=new Action(tr("&Rank"),this);
    rankac->setStatusTip(tr("search Ranks"));
    //connect
    searchac=new Action(tr("SearchName"));
    searchac->setStatusTip(tr("search by name"));
    //connect
    initTarget();
}

void MainWindow::initMenu(){
    operation=menuBar()->addMenu(tr("Operation"));
    operation->addAction(back2mainac);
    operation->addAction(back2upperac);

    mode=menuBar()->addMenu(tr("Mode"));
    mode->addAction(rankac);
    mode->addAction(searchac);

    target=menuBar()->addMenu(tr("Target"));
    web=target->addMenu(tr("Web"));
    object=target->addMenu(tr("Object"));

    for(int i=0;i<webnum;i++){
        web->addAction(webs[i]);
    }
    for(int i=0;i<objnum;i++){
        object->addAction(objs[i]);
    }
}

void MainWindow::addLevel(Level *level){
    stack.push_back(level);
    connect(level,SIGNAL(passLevel(Level*)),this,SLOT(addLevel(Level*)));

    //judge special level
    //because name in levelsearch should connect with the action obj
    LevelSearch* levelsearch=dynamic_cast<LevelSearch*>(level);
    if(levelsearch!=nullptr){//right
        qDebug() << "levelsearch!!";
        for(int i=0;i<objnum;i++){
            connect(objs[i],SIGNAL(actrigered(Action*)),levelsearch,SLOT(name_change(Action*)));
        }
    }
    else
        qDebug() << "is not levelsearch";


    //hide all expect the latest
    for(unsigned int i=0;i<stack.size()-1;i++){
        stack[i]->hide();
    }
}

void MainWindow::on_action(Action *checkedone){
    checkedone->setChecked(true); //check

    for(int i=0;i<webnum;i++){
        if(checkedone==webs[i]){
            for(int j=0;j<webnum;j++){
                if(i!=j) webs[j]->setChecked(false);
            }
            return;
        }
    }

    for(int i=0;i<objnum;i++){
        if(checkedone==objs[i]){
            for(int j=0;j<objnum;j++){
                if(i!=j) objs[j]->setChecked(false);
            }
            return;
        }
    }
}

void MainWindow::searchac_action(){ //when searchac(mode->searchname) triggered
    //add levelsearch

    //if current level is levelsearch, do nothing
    LevelSearch* levelsearch=dynamic_cast<LevelSearch*>(stack[stack.size()-1]);
    if(levelsearch!=nullptr){
        qDebug()<< "current level is already levelsearch!!";
        return; //do nothing
    }

    LevelMain* levelmain=dynamic_cast<LevelMain*>(stack[0]); //stack[0] must levelmain
    if(levelmain==nullptr){
        qDebug()<<"fatal error !! stack[0] isnot levelmain";
        return;
    }
    levelmain->searchbtn_clicked();
}

void MainWindow::back2m(){ //back to main level
    if(stack.size()==1) return;
    while(stack.size()>1){
        stack[stack.size()-1]->hide();
        delete stack[stack.size()-1];
        stack.pop_back();
    }
    stack[0]->show();
}

void MainWindow::back2u(){
    if(stack.size()==1) return;
    stack[stack.size()-1]->hide();
    delete stack[stack.size()-1];
    stack.pop_back();
    stack[stack.size()-1]->show();
}

MainWindow::~MainWindow()
{

}
