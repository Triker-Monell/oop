#ifndef EPISODES_H
#define EPISODES_H

//剧集数

#include "BaseData.h"
class Episodes:public BaseData{
    int number;
public:
    Episodes():BaseData("剧集数"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    bool operator<(Episodes& right);
    bool operator>(Episodes& right);
    bool operator==(Episodes& right);
};