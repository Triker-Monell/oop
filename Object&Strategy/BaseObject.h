#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

#include <string>
#include <vector>
#include "BaseData.h"
#include "Strategies.h"

class BaseObject{
protected:
    std::string type;
    std::vector<BaseData*> complexData;       //可以点击的复杂数据
    std::vector<BaseData*> simpleData;        //不可以点击的简单数据
public:
    friend class BaseStrategy;
    friend class ImdbStrategy;
    friend class DoubanStrategy;
    friend class TomatoStrategy;

    BaseObject(std::string _data, BaseStrategy* _strategy,std::string _type = "Base"){};
    //给出策略：IMDB/DOUBAN/TOMATO?见策略头文件

    virtual ~BaseObject()=0;                  //抽象类   //负责delete BaseData*

    virtual void show()=0;                    //展示全部信息
    // showType() : showData()  //string = xxx.showType() + " : " xxx.showData(); ..
    // 不同类型show的方式不同
    //bool setData(Basedata* _basedata);   // 修改一个元素：有，修改：true;没有，无变化：false
    //void pushData(Basedata* _basedata,bool isComplex);  // 新增一个元素


    BaseObject* queryObj(std::string _data);
    //查找本事物类对象是否有某个string（数据中字符串的子字符串）,有返回此对象的指针，没有返回nullptr

    std::vector<BaseData*> queryData(std::string _type);
    //查找某个类型的数据对象，没有返回vector：一个nullptr。

    std::vector<std::string> queryStr(std::string _data);
    //查找本事物类对象是否有某个string（数据中字符串的子字符串），返回一个string数组（包含子串对应的完整串），没有则返回只有一个元素的vector："No data."

    void sort(std::string _type);  //事物对象的排序
    //   sort,show ,type: data , score?
    //按照给出的排序原则把实例内部数据给排好序
    //排好，返回这个实例，  不能点击放上面，能点击放下面
    // baseobj -> sort -> 得分 /日期/XX
  };

#endif
