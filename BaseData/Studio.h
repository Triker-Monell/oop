#ifndef STUDIO_H
#define STUDIO_H

#include "BaseData.h"
//出品公司
class Studio:public BaseData{
public:
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif