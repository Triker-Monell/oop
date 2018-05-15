#ifndef _FILMMAKER_H
#define _FILMMAKER_H

#include "BaseData.h"
class FilmMaker:public BaseData{  //制片国家或地区
    std::string CountryOrRegion;
public:
    FilmMaker():BaseData("FilmMaker","string"){};
    FilmMaker(std::string _CountryOrRegion):
            BaseData("FilmMaker","string"),CountryOrRegion(_CountryOrRegion){};
    void setData(std::string newData);
    std::string getData()const;
};

#endif