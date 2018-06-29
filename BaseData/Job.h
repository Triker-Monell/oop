#ifndef JOB_H
#define JOB_H


#include "BaseData.h"
//职业
class Job:public BaseData{
public:
    Job():BaseData("职业"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif