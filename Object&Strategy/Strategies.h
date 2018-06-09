#ifndef _STRATEGIES_H
#define _STRATEGIES_H

//different ways to set imdb,douban & tomato
#include<string>

#include"BaseObject.h"

class BaseStrategy{
public:
  virtual set(std::string _data,BaseObject* _object)=0;
};

class ImdbStrategy: public BaseStrategy{
public:
  set(std::string _data,BaseObject* _object);
};

class DoubanStrategy{
public:
  set(std::string _data,BaseObject* _object);
};

class TomatoStrategy{
public:
  set(std::string _data,BaseObject* _object);
};

#endif
