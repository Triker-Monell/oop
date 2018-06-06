#ifndef DATEFORMAT_H
#define DATEFORMAT_H

#include <tuple>
#include <map>
class DateFormat{
public:
    virtual std::tuple<int,int,int> getNum(std::string data)=0;
};



/*
 * 标准日期格式
 * xxxx-xx-xx  年月日
 * 注意其中 - 可换为其他 任何 非/ 的字符
 */
class stdDateFormat:public DateFormat{
public:
    std::tuple<int,int,int>getNum(std::string data);
};



class EnglishDateFormat:public DateFormat{
    std::map<std::string,int> datemap={
            {"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},
            {"May",5},{"June",6},{"July",7},{"Aug",8},
            {"Sept",9},{"Oct",10},{"Nov",11},{"Dec",12}
    };
public:
    std::tuple<int,int,int>getNum(std::string data);
};

#endif