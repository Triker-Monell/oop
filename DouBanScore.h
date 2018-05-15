#ifndef _DOUBANSCORE_H
#define _DOUBANSCORE_H

#include "BaseScore.h"

class DouBanScore:public BaseScore{
    //basescore为豆瓣评分
    const static MaxStarNum=5; //最多星颗数
    double StarsPercents[MaxStarNum]; //每颗星的评分比例 小数 标准为3位小数
    int ReviewsCounted; //评价数量
public:
    DouBanScore():BaseScore("DouBanScore","complex"){};
    DouBanScore(std::string data);
    //标准字符串输入输出
    //例如: 6.6 评价人数160555 5星 7.7% 4星 29.8% 3星 49.9% 2星 10.5% 1星 2.2%
    //以空格分割
    void setData(std::string newData);
    std::string getData()const;

};

#endif