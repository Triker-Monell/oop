//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_ROTTENTOMATOES_BY_PEOPLE_H
#define MICP_ROTTENTOMATOES_BY_PEOPLE_H
#include "BaseCatcher.h"
class RottenTomatoes_by_people:public BaseCatcher{
public:
    RottenTomatoes_by_people();
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_ROTTENTOMATOES_BY_PEOPLE_H
