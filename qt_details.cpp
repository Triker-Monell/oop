#include "qt_details.h"
#include "qt_config.h"
#include <QMessageBox>
#include "BaseData/path.h"
Details::Details(QWidget *_central, QWidget *parent, bool _isScore):Level(_central,parent,false),isScore(_isScore)
{
    moreimage=new QPushButton("more image",parent);
    connect(moreimage,SIGNAL(clicked(bool)),this,SLOT(image_triggerd()));
}

void Details::inputdata(){
    //input

    Output* out=new stdOutput;

    int simplenum=obj->getSimpleSize();
    int simple_true_num=simplenum;
    if(isScore==true)  //has Score
        simple_true_num--;
    for(int i=0;i<simple_true_num;i++){
        simple t;
        const BaseData* bd=obj->func_not_clicked(i);
        std::string _text=bd->showType()+": "+bd->showData(out);

        qDebug() <<QString::fromStdString(_text);

        t.data=new QLabel(window);
        t.data->setText(QString::fromStdString(_text));
        spvec.push_back(t);
    }
    /*  // test
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
    */



    int complexnum=obj->getComplexSize();
    for(int i=0;i<complexnum;i++){
        complex t;
        const BaseData* bd=obj->func_clicked(i);

        bool _isPeople=dynamic_cast<const People*>(bd)!=nullptr;

        std::string temptype=bd->showType()+ ":";

        qDebug() << QString::fromStdString(temptype);

        t.type=new QLabel(QString::fromStdString(temptype),window);
        for(int j=0;j<8&&j<bd->num();j++){
            Label* single=new Label(window,_isPeople);
            std::string tempdata=bd->showSingle(j);

            qDebug() << QString::fromStdString(tempdata);

            single->setText(QString::fromStdString(tempdata));
            t.data.push_back(single);
        }
        if(false){  //old code
            t.more=new QPushButton(tr("more"),window);
            //connect!!!
        }
        else t.more=nullptr;
        cpvec.push_back(t);
    }

    /*  test
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
    */
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
        if(cpvec[i].more!=nullptr)
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
        if(cpvec[i].more!=nullptr)
            cpvec[i].more->hide();
    }

    poster->hide();
    moreimage->hide();
    if(isScore) score->hide();
    if(moreintro!=nullptr) moreintro->hide();
}

std::string Details::image_name_filter(std::string prev){
    for(unsigned int i=0;i<prev.size();i++){
        if(prev[i]==' ') prev[i]='_';
    }
    return prev;
}


void Details::image_triggerd(){
    std::string info[2]={PATH+"photos",PATH+"allphotos"};
    QString tmp=QString::fromStdString("see more images in "+info[0]+ " or " + info[1]);
    QMessageBox::information(nullptr,"Info",tmp,QMessageBox::Cancel);
}

Details::~Details(){
    delete obj; //delete
}
