#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "BaseData.h"
//使用语言

class Language:public BaseData{
public:
    Language():BaseData("语言"){};
    void setData(std::string);
    std::string showData()const;
};


#endif