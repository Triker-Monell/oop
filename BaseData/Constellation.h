#ifndef CONSTELLATION_H
#define CONSTELLATION_H

#include "BaseData.h"
//星座

class Constellation:public BaseData{
public:
    //只有datas[0]有数据
    Constellation():BaseData("星座"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};

#endif