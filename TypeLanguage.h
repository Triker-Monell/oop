#ifndef _TYPELANGUAGE_H
#define _TYPELANGUAGE_H

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


#endif