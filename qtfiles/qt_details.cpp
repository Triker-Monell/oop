#include "qt_details.h"
#include "qt_config.h"
Details::Details(QWidget *_central, QWidget *parent, bool _isScore):Level(_central,parent),isScore(_isScore)
{
    //object initial


    //image
    /*
    QDir dir("./images");
    if(!dir.exists()){
        qDebug() << "wrong dir" ;
    }
    */
    poster=new QLabel(parent);
    QImage image(":/test.jpg");
    poster->setPixmap(QPixmap::fromImage(image));
    poster->resize(image.width(),image.height());

    moreimage=new QPushButton("more images",parent);
    moreintro=nullptr; //this is movie


    //input data
    inputdata();

    //intial score if has
    if(isScore){
        score=Config::instance().getScoreWidget(window);
         //score need obj info and init
    }
    else score=nullptr;


    //size and position
    pushlayout();

}

void Details::inputdata(){
    //input

    //test
    int simplenum=4;
    /*
    for(int i=0;i<simplenum;i++){
        simple t;
        t.data=new QLabel(tr("num"),window);
        spvec.push_back(t);
    }*/
    simple t;
    t.data=new QLabel(tr("MovieName: Jurassic World: Fallen Kingdom"),window);
    spvec.push_back(t);
    t.data=new QLabel(tr("Type: Action/Adventure"),window);
    spvec.push_back(t);
    t.data=new QLabel(tr("Language: English"),window);
    spvec.push_back(t);
    t.data=new QLabel(tr("ReleaseDate: 2018/06/15"),window);
    spvec.push_back(t);
    t.data=new QLabel(tr("Runtime: 128 min"),window);
    spvec.push_back(t);
    t.data=new QLabel(tr("OfficialWeb: www.xxxxx.com"),window);
    spvec.push_back(t);



    /*
    int complexnum=4;
    for(int i=0;i<complexnum;i++){
        complex t;
        t.type=new QLabel(tr("type"),window);
        for(int j=0;j<6;j++){
            Label* single=new Label(window);
            single->setText(tr("single"));
            t.data.push_back(single);
        }
        t.more=new QPushButton(tr("more"),window);
        cpvec.push_back(t);
    }

    */
    complex tc;
    Label* single;
    tc.type=new QLabel(tr("LeadingActor:"),window);
    for(int i=0;i<6;i++){
        single=new Label(window);
        QString str="name"+QString::number(i);
        single->setText(str);
        tc.data.push_back(single);
    }
    tc.more=new QPushButton(tr("more"),window);
    cpvec.push_back(tc);
    tc.data.clear();

    tc.type=new QLabel(tr("Director:"),window);
    for(int i=0;i<6;i++){
        single=new Label(window);
        QString str="name"+QString::number(i);
        single->setText(str);
        tc.data.push_back(single);
    }
    tc.more=new QPushButton(tr("more"),window);
    cpvec.push_back(tc);
    tc.data.clear();

    tc.type=new QLabel(tr("Writer:"),window);
    for(int i=0;i<6;i++){
        single=new Label(window);
        QString str="name"+QString::number(i);
        single->setText(str);
        tc.data.push_back(single);
    }
    tc.more=new QPushButton(tr("more"),window);
    cpvec.push_back(tc);
    tc.data.clear();
}

void Details::pushlayout(){
    glayout=new QGridLayout;
    int linenum=spvec.size()+cpvec.size();

    glayout->setSpacing(10);
    glayout->setMargin(20);

    glayout->addWidget(poster,0,0,linenum-1,4);
    glayout->addWidget(moreimage,linenum-1,0,1,4);
    for(int i=0;i<spvec.size();i++){
        glayout->addWidget(spvec[i].data,i,4,1,5);
    }
    for(int i=0;i<cpvec.size();i++){
        int real_shownum=(shownum<cpvec[i].data.size())? shownum:cpvec[i].data.size();
        glayout->addWidget(cpvec[i].type,spvec.size()+i,4,1,1);
        for(int j=0;j<cpvec[i].data.size();j++){
            glayout->addWidget(cpvec[i].data[j],spvec.size()+i,5+j,1,1);
        }

        //judge
        glayout->addWidget(cpvec[i].more,spvec.size()+i,4+cpvec[i].data.size(),1,1);
    }

    //score if has;
    if(isScore) glayout->addWidget(score,0,9,5,7);

    if(central->layout()!=nullptr){
        qDebug()<< "has laytout";
        delete central->layout();
    }


    central->setLayout(glayout);
}

void Details::show(){
    for(int i=0;i<spvec.size();i++){
        spvec[i].data->show();
    }
    for(int i=0;i<cpvec.size();i++){
        cpvec[i].type->show();
        for(int j=0;j<cpvec[i].data.size();j++)
            cpvec[i].data[j]->show();

        //judge
        cpvec[i].more->show();
    }

    poster->show();
    moreimage->show();
    if(isScore) score->show();
    if(moreintro!=nullptr) moreintro->show();
}

void Details::hide(){
    for(int i=0;i<spvec.size();i++){
        spvec[i].data->hide();
    }
    for(int i=0;i<cpvec.size();i++){
        cpvec[i].type->hide();
        for(int j=0;j<cpvec[i].data.size();j++)
            cpvec[i].data[j]->hide();

        //judge
        cpvec[i].more->hide();
    }

    poster->hide();
    moreimage->hide();
    if(isScore) score->hide();
    if(moreintro!=nullptr) moreintro->hide();
}

Details::~Details(){

}
