//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_DOUBAN_BY_PEOPLE_H
#define MICP_DOUBAN_BY_PEOPLE_H
#include "BaseCatcher.h"
class Douban_by_people:public BaseCatcher{
public:
    Douban_by_people();
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_DOUBAN_BY_PEOPLE_H
