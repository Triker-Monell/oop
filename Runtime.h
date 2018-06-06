#ifndef RUNTIME_H
#define RUNTIME_H

#include "BaseData.h"

//片长
class Runtime:public BaseData{
    int minute;
public:
    Runtime():BaseData("片长"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    bool operator<(Runtime& right);
    bool operator>(Runtime& right);
    bool operator==(Runtime& right);
};


#endif