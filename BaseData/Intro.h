#ifndef INTRO_H
#define INTRO_H

#include "BaseData.h"
//简介
//长串字符串,中间应当没有任何/字符
//字符串储存在datas[0]
class Intro:public BaseData{
public:
    Intro():BaseData("简介"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};



#endif