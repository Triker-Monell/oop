#ifndef TYPE_H
#define TYPE_H

#include "BaseData.h"
//类型

class Type:public BaseData{
public:
    Type():BaseData("类型"){};
    void setData(std::string data);
    std::string showData()const;
};

#endif