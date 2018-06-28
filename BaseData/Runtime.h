#ifndef RUNTIME_H
#define RUNTIME_H

#include "BaseData.h"

//片长
//标准格式 数字+单位(语言任意)  数字需以分钟为单位
class Runtime:public BaseData{
    int minute;
public:
    Runtime():BaseData("片长"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    bool operator<(Runtime& right);
    bool operator>(Runtime& right);
    bool operator==(Runtime& right);
};


#endif