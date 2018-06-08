#ifndef TYPE_H
#define TYPE_H

#include "BaseData.h"
//类型

class Type:public BaseData{
public:
    Type():BaseData("类型"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;


    bool isType(std::string _type);
};

#endif