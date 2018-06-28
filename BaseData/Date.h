#ifndef DATE_H
#define DATE_H

#include "BaseData.h"
#include "Format/DateFormat.h"
//日期  可派生为上映日期 生日等等

class Date:public BaseData{
    int year;
    int month;
    int day;
public:
    Date(std::string _type):BaseData(_type){};

    bool operator>(const Date& right)const;
    bool operator<(const Date& right)const;
    bool operator==(const Date& right)const;

    void setDateNum(DateFormat* format);
};




//上映日期
class ReleaseDate:public Date{
public:
    ReleaseDate():Date("上映日期"){};
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


//生日
class BirthDate:public Date{
public:
    BirthDate():Date("出生日期"){}
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;
};


#endif