#ifndef PEOPLE_H
#define PEOPLE_H

#include "BaseData.h"
//人  用于电影/电视剧等界面
class People:public BaseData{
public:
    People(std::string _type):BaseData(_type){};
    ~People(){};
};

#endif