#ifndef SEASON_H
#define SEASON_H

#include "BaseData.h"
//第几季
class Season:public BaseData{
public:
    Season():BaseData("季"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};