#ifndef PLACE_H
#define PLACE_H

#include "BaseData.h"
//地区基类 可派生为 制片地区 出生地 等等

class Place:public BaseData{
public:
    Place(std::string _type):BaseData(_type){};
};




//制片地区
class FilmMakingArea:public Place{
public:
    FilmMakingArea():Place("制片地区"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


//出生地
class BirthPlace:public Place{
public:
    BirthPlace():Place("出生地"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif