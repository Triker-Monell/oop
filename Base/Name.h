#ifndef NAME_H
#define NAME_H

#include "BaseData.h"

class Name:public BaseData{
    //datas[0]为最常用名称，其他为别名
public:
    Name(std::string _type):BaseData(_type+"名"){};
    /*
     * 输入输出标准格式 名称之间以/隔开 第一个名称为最常用名称
     * name1/name2/name3
     */
    void setData(std::string data,Input* in) final ;
    std::string showData(Output* out)const final;
};


//电影名
class MovieName:public Name{
public:
    MovieName():Name("电影"){};
};

//人名
class PersonName:public Name{
public:
    PersonName():Name("姓"){};
};

//电视剧名
class TVplayName:public Name{
public:
    MovieName():Name("电视剧"){};
};
#endif
