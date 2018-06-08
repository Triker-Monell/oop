#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

#include <string>
#include <vector>
#include "BaseData.h"
#include "Strategies.h"

class BaseObject{
protected:
    std::vector<BaseData*> complexData;       //可以点击的复杂数据
    std::vector<BaseData*> simpleData;        //不可以点击的简单数据
public:
    friend class ImdbStrategy;
    friend class DoubanStrategy;
    friend class TomatoStrategy;

    BaseObject(std::string _data, BaseStrategy* _strategy){};    //给出策略：IMDB/DOUBAN/TOMATO?见策略头文件
    virtual ~BaseObject()=0;                  //抽象类   //负责delete BaseData*
    virtual void show()=0;                    //展示全部信息
    // showType() : showData()  //string = xxx.showType() + " : " xxx.showData(); ..
    // 不同类型show的方式不同
    void setData(std::string _data,std::string _type,bool isComplex);   // 修改一个元素!isComplex means simple
    void pushData(std::string _data,std::string _type,bool isComplex);  // 新增一个元素

    std::string query(std::string _data);      //查找信息，没有返回 "No data."
    void sort(std::string _type);              //事物对象的排序
    //   sort,show ,type: data , score?
    //按照给出的排序原则把实例内部数据给排好序
    //排好，返回这个实例，  不能点击放上面，能点击放下面
    // baseobj -> sort -> 得分 /日期/XX
  };

#endif //_BASEOBJECT_H
