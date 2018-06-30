#ifndef BIRTHINFO_H
#define BIRTHINFO_H


#include "BaseData.h"

//出生信息
//数据只在datas[0]
class BirthInfo:public BaseData{
public:
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif