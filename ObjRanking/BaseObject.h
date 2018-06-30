#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

#include <string>
#include <vector>
#include "BaseData/allBaseData.h"
#include "Strategies.h"
#include "Catcher/allCatcher.h"

class BaseObject{
protected:
    std::string name;       //名字
    std::string type;       //Movie/TV/Person
    std::vector<BaseData*> complexData;       //可以点击的复杂数据    ,show secondly
    std::vector<BaseData*> simpleData;        //不可以点击的简单数据  ,show firstly
    bool hasScore; //是否有评分 由派生类决定 movie tv有  person没有
    //如果有 评分在simplevector最后一个  使用其他数据 num-1
public:
    BaseObject(std::string _name,BaseStrategy* _strategy,std::string _type); //type由派生类默认值给出

    virtual ~BaseObject()=0;                  //抽象类   //负责delete BaseData*

    std::string getName();
    std::string getType();
    int getComplexSize();
    int getSimpleSize();

    const BaseData* func_clicked(int _num);        //返回num位置的 complexData*
    // COMMENT: const BaseData* mybasedata = func_clicked(1)
    const BaseData* func_not_clicked(int _num);    //返回num位置的 simpleData*
    const BaseData* queryData(std::string _type);
};

#endif

/*  IGNORE THESE:   //本来要实现检索功能？

    //virtual void show()=0;                    //展示全部信息
    // showType() : showData()  //string = xxx.showType() + " : " xxx.showData(); ..
    // 不同类型show的方式不同
    //bool setData(Basedata* _basedata);   // 修改一个元素：有，修改：true;没有，无变化：false
    //void pushData(Basedata* _basedata,bool isComplex);  // 新增一个元素

    BaseObject* queryObj(std::string _data);          //模糊搜索
    //查找本事物类对象是否有某个string（数据中字符串的子字符串）,有返回此对象的指针，没有返回nullptr

    std::vector<BaseData*> queryData(std::string _type);
    //查找某个类型的数据对象，没有返回vector：一个nullptr。

    std::vector<std::string> queryStr(std::string _data);       //模糊搜索
    //查找本事物类对象是否有某个string（数据中字符串的子字符串），返回一个string数组（包含子串对应的完整串），没有则返回只有一个元素的vector："No data."

*/
