#ifndef PRODUCER_H
#define PRODUCER_H
#include "BaseData.h"

//制作商
class Producer:public BaseData{
public:
    Producer():BaseData("制作商"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};




#endif