#ifndef LEADINGACTOR_H
#define LEADINGACTOR_H

#include "People.h"
//主演
class LeadingActor:public People{
public:
    LeadingActor():People("主演"){};
    void setData(std::string data);
    std::string showData()const;
};


#endif