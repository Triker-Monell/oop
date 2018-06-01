#ifndef _TYPELANGUAGE_H
#define _TYPELANGUAGE_H

class TypeLanguage{
public:
    virtual const std::string getType(int num)=0;
    virtual int searchNum(std::string _type)=0;  //找到类型所对应的编号  返回-1代表不存在
};

class ChineseTypeLanguage:TypeLanguage{
      static const std::string ChineseType[];
public:
    const std::string getType(int num);
    int searchNum(std::string _type);
};

class EnglishTypeLanguage:TypeLanguage{
     static const std::string EnglishType[]={
            "Comedy","Adventure","Fantasy","Mystery","Thriller",
            "Documentary","War","Western","Romance","Drama",
            "Horror","Action","ScienceFiction","Crime","Biography",
            "History","Sports"
    };
public:
    const std::string getType(int num);
    int searchNum(std::string _type);
};


#endif