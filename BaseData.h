#ifndef _BASEDATA_H
#define _BASEDATA_H

#include<string>
#include<iostream>
class BaseData{
private:
    std::string DataName; //数据名称  类名.......
    std::string Type; //数据类型  若为complex则代表有多个数据成员
    void setDateName(std::string _dataname){DataName=_dataname;};
public:
    BaseData(std::string _name,std::string _type):DataName(_name),Type(_type){};
    std::string getDataName()const{return DataName;};
    std::string getType()const{return Type};  //得到数据类型(int/string.....)
    virtual void setData(std::string newData)=0;
    virtual std::string getData() const =0; //将数据都转换成string 然后返回
    virtual ~BaseData()=0;
};

#endif