#ifndef _BASESTRATEGY_H
#define _BASESTRATEGY_H

#include<vector>
#include<string>

#include"BaseObject.h"

class BaseStrategy{
public:
  // ???
  //virtual work(std::vector<BaseData*>& _complexData, std::vector<BaseData*>& _simpleData,std::string _data,)=0;
};


// Warning：
//需要各种策略继承这一 策略基类
// 如 Douban_by_TV: public BaseStrategy

#endif