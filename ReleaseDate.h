#ifndef _RELEASEDATE_H
#define _RELEASEDATE_H

#include "BaseData.h"
#include "RDformat.h"


class ReleaseDate:public BaseData{
    //*******
    //标准格式  (年月日)  xxxx-xx-xx(xxxxx)  其中括号及其中内容是可选的
    //*******
    int year;
    int month;
    int day;
    std::string CountryOrRegion;  //地区上映时间  这个数据是可选的 不选则为空
    RDformat* format;
public:
    ReleaseDate(RDformat* _format):BaseData("ReleaseDate","complex"),year(0),month(0),day(0),format(_format){};
    ReleaseDate(RDformat* _format,int _year,int _month,int _day,std::string _CountryOrRegion=""):
            BaseData("ReleaseDate","complex"),
            format(_format),year(_year),month(_month),day(_day),CountryOrRegion(_CountryOrRegion){};
    ReleaseDate(RDformat* _format,std::string date);
        //这个构造函数将从date中提取处年月日，输入格式标准依据format

    void setData(std::string newData);//与上排构造函数输入方式一样 以format格式读取数据
    std::string getData()const; //返回标准格式 以format格式返回


    void setRD(std::string newData,RDformat* _format=format);//以其他格式读入数据，默认为初始化时的format
    std::string getRD(RDformat* _format=format)const;//可以以其他格式读出数据，默认为初始化时的格式

    //****下列三个get都返回数字字符串*****
    void setYear(int _year);
    std::string getYear()const;
    void setMonth(int _month);
    std::string getMonth()const;
    void setDay(int _day);
    std::string getDay()const;
    //********************************

    bool operator>(const ReleaseDate& right)const;
    bool operator<(const ReleaseDate& right)const;
    bool operator==(const ReleaseDate& right)const;//只针对日期是否相同，不针对地区

    //流运算符重载均为标准格式输出
    //friend std::istream& operator>>(std::istream& in,ReleaseDate& right);
    friend std::ostream& operator<<(std::ostream& out,const ReleaseDate& right)const;

    ~ReleaseDate(){delete format;};
};

#endif