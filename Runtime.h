#ifndef _RUNTIME_H
#define _RUNTIME_H

#include "BaseData.h"
class Runtime:public BaseData{
    //标准单位 分钟
    int minute;
public:
    Runtime():BaseData("Runtime","int"),minute(0){};
    Runtime(int _min):BaseData("Runtime","int"),minute(_min){};

    void setData(std::string newData){};
    std::string getData()const;

    void setMinute(int _min);
    int getMinute()const;

    friend bool operator>(const Runtime& right);
    friend bool operator<(const Runtime& right);
    friend bool operator==(const Runtime& right);
};

#endif