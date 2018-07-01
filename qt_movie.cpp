#include "qt_movie.h"
#include <QDebug>
#include <QDir>
#include "qt_config.h"
#include "ObjRanking/MovieObject.h"
#include <string>
#include <QDebug>
#include "qt_person.h"
#include "BaseData/path.h"
Movie::Movie(QString _name, QWidget *_central, QWidget *parent):Details(_central,parent,true)
{
    //object initial
    BaseStrategy* _strategy=Config::instance().getStrategy(parent);
    std::string str_name=_name.toStdString();
    obj=new MovieObject(str_name,_strategy);





    //image
    /*
    QDir dir("./images");
    if(!dir.exists()){
        qDebug() << "wrong dir" ;
    }
    */
    poster=new QLabel(parent);

    std::string poster_path=PATH+"photos"+"/"+Details::image_name_filter(str_name)+std::to_string(0)+".jpg";
    qDebug() << QString::fromStdString(poster_path);

    QImage image(poster_path.c_str());
    QPixmap temppix=QPixmap::fromImage(image);
    temppix=temppix.scaled(300,380,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    poster->setPixmap(temppix);
    poster->resize(image.width(),image.height());

    //moreimage=new QPushButton("more images",parent);   in base  construsction
    moreimage->resize(image.width(),moreimage->height());
    moreimage->setMaximumWidth(image.width());
    moreintro=nullptr; //this is movie


    //input data(base class)
    inputdata();

    //intial score if has
    if(isScore){
        const Score* _score=dynamic_cast<const Score*>(obj->func_not_clicked(obj->getSimpleSize()-1));

        score=Config::instance().getScoreWidget(_score,window);
         //score need obj info and init
    }
    else score=nullptr;


    //size and position(base class)
    pushlayout();



    //跳转connect
    for(unsigned int i=0;i<cpvec.size();i++){
        for(unsigned int j=0;j<cpvec[i].data.size();j++){
            connect(cpvec[i].data[j],SIGNAL(triggered(QString,bool)),this,SLOT(leap(QString,bool)));
        }
    }
}

void Movie::leap(QString _text, bool _isPeople){

    Details* detail;

    if(_isPeople){
        qDebug() << _text<< " is triggered " << "  people";

        detail=new Person(_text,central,window);
    }
    else{
        qDebug() << _text<< " is triggered " << "  movie";
        detail=Config::instance().getDetails(_text,central,window);

    }
    this->hide();
    detail->show();

    passLevel(detail);
}


Movie::~Movie(){

}
