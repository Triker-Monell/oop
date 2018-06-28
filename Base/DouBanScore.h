#ifndef DOUBANSCORE_H
#define DOUBANSCORE_H

#include "Score.h"
#include "Format/DBSio.h"
class DouBanScore:public Score{
    /*
     * datas[0] 为评分  datas[i] 表示i星的占比 带有%
     * Score标准格式
     * 6.1  5.9%  22.9%  48.8% 17.7% 4.8%
     * 分别是 评分 五星 四星 三星 二星 一星
     */

    // MarStar=5 定义在DBio.h里
    extern const int MarStar=5;
    double points[MarStar+1];

public:
    DouBanScore():Score("豆瓣评分"){};

    //注意这里不用stdInput 和stdOutput
    //而是用DBSinput和DBSoutput
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    double getScore()const;
    double getRate(int star)const;

    //比较只比较豆瓣评分的大小
    bool operator<(DouBanScore& right);
    bool operator>(DouBanScore& right);
    bool operator==(DouBanScore& right);

};



#endif