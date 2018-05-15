#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#include "BaseData.h"
class Language:public BaseData{
    std::string language;
public:
    Language():BaseData("Language","string"){};
    Language(std::string _language):BaseData("Language","string"),language(_language){};
    void setData(std::string newData);
    std::string getData()const;
};

#endif