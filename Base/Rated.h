#ifndef RATED_H
#define RATED_H

//分级
#include "BaseData.h"
class Rated:public BaseData{
public:
    Rated():BaseData("分级"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out) const
    ~Rated(){};
};


#endif