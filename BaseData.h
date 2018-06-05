#ifndef BASEDATA_H
#define BASEDATA_H

#include <string>
#include <vector>
#include <iostream>

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
    const std::string showType() const{
        return type;
    }

};


#endif