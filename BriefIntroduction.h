#ifndef _BRIEFINTRODUCTION_H
#define _BRIEFINTRODUCTION_H

#include "BaseData.h"
class BriefIntroduction:public BaseData{
    std::string content;
public:
    BriefIntroduction():BaseData("BriefIntroduction","string"){};
    BriefIntroduction(std::string _content):
            BaseData("BriefIntroduction","string"),content(_content){};
    void setData(std::string newData);
    std::string getData()const;
};

#endif