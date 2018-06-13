#ifndef _STRATEGIES_H
#define _STRATEGIES_H

#include<vector>
#include<string>

#include"BaseObject.h"

class BaseStrategy{
public:
  virtual work(std::vector<BaseData*>& _complexData, std::vector<BaseData*>& _simpleData,std::string _data,)=0;   
};

// 请派生

#endif
