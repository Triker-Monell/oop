#ifndef _RDFORMAT_H
#define _RDFORMAT_H

#include <tuple>
#include <sstream>
class RDformat{  //放映时期的格式
public:
    virtual std::tuple<int,int,int,std::string> setRD(std::string newData)=0;
    virtual std::string getRD(int year,int month,int day,std::string CountryorRegion)=0;
};


//以下根据不同电影网站实现不同的格式
class DouBanRDformat:public RDformat{
public:
    std::tuple<int,int,int,std::string> setRD(std::string newData);
    std::string getRD(int year,int month,int day,std::string CountryorRegion);
};


class RottenTomatoesRDformat:public RDformat{
    const static std::string MONTH[]={
            "","Jan","Feb","Mar","Apr","May","June",
            "July","Aug","Sept","Oct","Nov","Dec"
    }
public:
    std::tuple<int,int,int,std::string> setRD(std::string newData);
    std::string getRD(int year,int month,int day,std::string CountryorRegion);
};

#endif