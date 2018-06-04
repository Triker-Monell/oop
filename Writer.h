#ifndef WRITER_H
#define WRITER_H

#include "People.h"
//编剧
class Writer:public People{
public:
    Writer():People("编剧"){};
    void setData(std::string data);
    std::string showData()const;
};


#endif