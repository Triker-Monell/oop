#ifndef SIMILAR_H
#define SIMILAR_H

#include "BaseData.h"
class Similar:public BaseData{
public:
    Similar(std::string _type):BaseData(_type){};
};


class SimilarMovie:public Similar{
public:
    SimilarMovie():Similar("相似电影"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out) const;
};


#endif