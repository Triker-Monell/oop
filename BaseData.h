#ifndef BASEDATA_H
#define BASEDATA_H

<<<<<<< HEAD
#include <string>
#include <vector>
=======
#include<string>
#include<iostream>
>>>>>>> 87fb22aafdbc03445838e6a95218257c8e6c79b4
class BaseData{
    const std::string type;
protected:
    std::vector<std::string> datas;
public:
    BaseData(std::string _type):type(_type){};
    virtual void setData(std::string data) =0;
    virtual std::string showData() const =0;
    int num()const{
        return datas.size();
    }
    std::string showType() const{
        return type;
    }
};


#endif