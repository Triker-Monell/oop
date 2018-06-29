#ifndef FAMILY_H
#define FAMILY_H

#include "BaseData.h"
//家庭
class Family:public BaseData{
public:
    //  用/分割
    Family():BaseData("家庭"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif