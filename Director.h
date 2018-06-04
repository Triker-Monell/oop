#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "People.h"

//导演类
class Director:public People{
public:
    Director():People("导演"){};
    void setData(std::string data);
    std::string showData()const;
};

#endif