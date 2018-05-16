#ifndef _MOVIETYPE_H
#define _MOVIETYPE_H

#include "BaseData.h"
class MovieType:public BaseData{   //一个类型一个实例  便于之后搜索
    int type;
    bool isChinese;  //是否为中文，是则为true 不是(即英文)则为false
    //默认为中文
public:
    enum{
        Comedy,Adventure,Fantasy,Mystery,Thriller,
        Documentary,War,Western,Romance,Drama,
        Horror,Action,ScienceFiction,Crime,Biography,
        History,Sports
    };
    const static std::string EnglishTYpe[]={
            "Comedy","Adventure","Fantasy","Mystery","Thriller",
            "Documentary","War","Western","Romance","Drama",
            "Horror","Action","ScienceFiction","Crime","Biography",
            "History","Sports"
    };
    const static std::string ChineseType[]={
            "喜剧","冒险","奇幻","悬疑","惊悚",
            "纪录","战争","西部","爱情","剧情",
            "恐怖","动作","科幻","犯罪","传记",
            "历史","运动"
    };   //采用MovieType::ChineseType[MovieType::Comedy]来获得对应的中文

    MovieType():BaseData("MovieType","int"),type(-1),isChinese(true){};
    MovieType(int _type):BaseData("MovieType","int"),type(_type),{};
    MovieType(std::string _type);//参数可为中文或者英文


    void setData(std::string newData);
        //参数直接为字符串 可为中文或英文 将会根据语言更改isChinese
    void setData_byMovieType(int _type); //参数应为MovieType::Comedy等等
    std::string getData()const; //根据isChinese选择语言输出，默认为中文
    std::string getChineseType()const;
    std::string getEnglishType()const;

    int getTypeNum(std::string _type)const; //给定类型，得到类型编号，便于中英文转换，返回-1代表不存在该类型
};

#endif