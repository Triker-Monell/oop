#ifndef _STRATEGIES_H
#define _STRATEGIES_H

//different ways to set imdb,douban & tomato
#include<string>
#include <vector>
#include "../BaseData/BaseData.h"
#include <iostream>
#include <fstream>
class BaseCatcher;
class BaseStrategy{
protected:
    BaseCatcher* bas;//用来生成对应爬虫派生类
    
    void initialTXT(std::string _filename,std::string _name);//这个用来读取文档传过来的名字信息，即需要爬取的东西的名称
public:
    BaseStrategy();
    virtual void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData)=0;//功能实现，见cpp或Strategy说明
};
//以下都是派生类
class Imdb_movies_Strategy: public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

class Douban_movies_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

class Tomato_movies_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};
class Imdb_TV_Strategy: public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

class Douban_TV_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

class Tomato_TV_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};
class Imdb_people_Strategy: public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};
/*
class Douban_people_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};
*/
class Tomato_people_Strategy:public BaseStrategy{
public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

#endif
