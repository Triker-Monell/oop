#ifndef SEX_H
#define SEX_H

#include "BaseData.h"
//性别
class Sex:public BaseData{
public:
    //只有datas[0]有数据
    Sex():BaseData("性别"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};

#endif