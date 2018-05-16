#ifndef _RELEASEDATE_H
#define _RELEASEDATE_H

#include "BaseData.h"
class ReleaseDate:public BaseData{
    //*******
    //标准格式(年月日)  xxxx-xx-xx(xxxxx)  其中括号及其中内容是可选的
    //*******
    int year;
    int month;
    int day;
    std::string CountryOrRegion;  //地区上映时间  这个数据是可选的 不选则为空
public:
    ReleaseDate():BaseData("ReleaseDate","complex"),year(0),month(0),day(0){};
    ReleaseDate(int _year,int _month,int _day,std::string _CountryOrRegion=""):
            BaseData("ReleaseDate","complex"),
            year(_year),month(_month),day(_day),CountryOrRegion(_CountryOrRegion){};
    ReleaseDate(std::string date);
        //这个构造函数将从date中提取处年月日，因此需要输入标准格式xxxx-xx-xx(xxx)
        //若后面有括号则将括号内的内容设置为地区信息，无括号则不设置地区信息

    void setData(std::string newData);//与上排构造函数输入方式一样
    std::string getData()const; //返回标准格式

    void setYear(int _year);
    void setYear(std::string _year);
    std::string getYear()const;
    void setMonth(int _month);
    void setMonth(std::string _month);
    std::string getMonth()const;
    void setDay(int _day);
    void setDay(std::string _day);
    std::string getDay()const;

    friend bool operator>(const ReleaseDate& right)const;
    friend bool operator<(const ReleaseDate& right)const;
    friend bool operator==(const ReleaseDate& right)const;//只针对日期是否相同，不针对地区

    //流运算符重载均为标准格式输入与输出
    friend std::istream& operator>>(std::istream& in,ReleaseDate& right);
    friend std::ostream& operator<<(std::ostream& out,const ReleaseDate& right)const;
};

#endif