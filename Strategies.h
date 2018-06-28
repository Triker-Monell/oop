#ifndef _STRATEGIES_H
#define _STRATEGIES_H

//different ways to set imdb,douban & tomato
#include<string>
#include <vector>
#include "BaseData.h"
#include <iostream>
class BaseCatcher;
class BaseStrategy{
protected:
    BaseCatcher* bas;
public:
    BaseStrategy();
    virtual void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData)=0;
};

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

class Douban_people_Strategy:public BaseStrategy{
 public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

class Tomato_people_Strategy:public BaseStrategy{
public:
    void exec(std::string _name,std::vector<BaseData*>& complexData,std::vector<BaseData*>& simpleData);
};

#endif
