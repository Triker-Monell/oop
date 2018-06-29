#ifndef OFFICIALSITES_H
#define OFFICIALSITES_H

#include "BaseData.h"
//官方网站
class OfficialSites:public BaseData{
public:
    //标准输入输出  不同网站用/分割
    OfficialSites():BaseData("官方网站"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif
