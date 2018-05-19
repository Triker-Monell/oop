#ifndef _MOVIETYPE_H
#define _MOVIETYPE_H

#include "BaseData.h"


class TypeLanguage{
public:
    virtual std::string getType(int num)=0;
    virtual int searchNum(std::string _type)=0;  //找到类型所对应的编号  返回-1代表不存在
};

class ChineseTypeLanguage:TypeLanguage{
    const static std::string ChineseType[]={
            "喜剧","冒险","奇幻","悬疑","惊悚",
            "纪录","战争","西部","爱情","剧情",
            "恐怖","动作","科幻","犯罪","传记",
            "历史","运动"
    };
public:
    std::string getType(int num);
    int searchNum(std::string _type);
};

class EnglishTypeLanguage:TypeLanguage{
    const static std::string EnglishType[]={
            "Comedy","Adventure","Fantasy","Mystery","Thriller",
            "Documentary","War","Western","Romance","Drama",
            "Horror","Action","ScienceFiction","Crime","Biography",
            "History","Sports"
    };
public:
    std::string getType(int num);
    int searchNum(std::string _type);
};



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