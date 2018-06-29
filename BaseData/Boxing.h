#ifndef BOXING_H
#define BOXING_H

#include "BaseData.h"
//票房 纯字符串
//字符串里应该没有/分割
//字符串放在datas[0]
class Boxing:public BaseData{
public:
    Boxing():BaseData("票房"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif