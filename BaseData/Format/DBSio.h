#ifndef DBSIO_H
#define DBSIO_H

#include "IOFormat.h"

/*
 * 标准input格式
 * 6.1  5.9%  22.9%  48.8% 17.7% 4.8%
 * 分别是 评分 五星 四星 三星 二星 一星
 *
 * 标准output格式
 * 豆瓣评分6.1 五星5.9% .......
 * (不推荐使用,而采用专门的接口)
 */

const int MaxStar=5;

class DBSinput:public Input{
public:
    void input(std::vector<std::string>& vec,std::string data);
};

class DBSoutput:public Output{
public:
    std::string output(const std::vector<std::string>& vec);
};


#endif