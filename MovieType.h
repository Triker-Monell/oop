#ifndef _MOVIETYPE_H
#define _MOVIETYPE_H

#include "BaseData.h"
#include "TypeLanguage.h"


class MovieType:public BaseData{   //一个类型一个实例  便于之后搜索
    int type;
    TypeLanguage* typelanguage;
public:
    enum{
        Comedy,Adventure,Fantasy,Mystery,Thriller,
        Documentary,War,Western,Romance,Drama,
        Horror,Action,ScienceFiction,Crime,Biography,
        History,Sports
    };

    MovieType(TypeLanguage* tlanguage,int _type=-1):
            BaseData("MovieType","int"),type(-1),typelanguage(tlanguage){};
    MovieType(TypeLanguage* tlanguage,std::string _type);//_type的语言应为tlanguage对应语言


    void setData(std::string newData) override ;//参数应为TypeLanguage对应的语言
    void setData_byMovieType(int _type); //参数应为MovieType::Comedy等等
    std::string getData()const override ; //根据TypeLanguage的语言输出

    std::string getType(TypeLanguage* tl=typelanguage)const; //根据参数给出的语言输出


    ~MovieType(){delete typelanguage;};
};





#endif