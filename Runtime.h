#ifndef RUNTIME_H
#define RUNTIME_H

#include "BaseData.h"

//片长
class Runtime:public BaseData{
public:
    Runtime():BaseData("片长"){};
    void setData(std::string data);
    std::string showData()const;
};


#endif