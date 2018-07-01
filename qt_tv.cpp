#include "qt_tv.h"
#include "qt_config.h"
#include "BaseData/path.h"
Tv::Tv(QString _name,QWidget* _central,QWidget* parent):Details(_central,parent,true)
{
    //object initial
    BaseStrategy* _strategy=Config::instance().getStrategy(parent);
    std::string str_name=_name.toStdString();
    obj=new TVObject(str_name,_strategy);





    //image
    /*
    QDir dir("./images");
    if(!dir.exists()){
        qDebug() << "wrong dir" ;
    }
    */
    poster=new QLabel(parent);
    std::string poster_path=PATH+"photos"+"/"+Details::image_name_filter(str_name)+std::to_string(0)+".jpg";
    QImage image(poster_path.c_str());
    QPixmap temppix=QPixmap::fromImage(image);
    temppix=temppix.scaled(300,380,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    poster->setPixmap(temppix);
    poster->resize(image.width(),image.height());


    //moreimage=new QPushButton("more images",parent);  in base
    moreintro=nullptr; //this is movie


    //input data(base class)
    inputdata();

    //intial score if has
    const Score* _score=dynamic_cast<const Score*>(obj->func_not_clicked(obj->getSimpleSize()-1));
    score=Config::instance().getScoreWidget(_score,window);
    //score need obj info and init


    //size and position(base class)
    pushlayout();
}

Tv::~Tv(){

}
