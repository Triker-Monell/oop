//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_IMDB_BY_PEOPLE_H
#define MICP_IMDB_BY_PEOPLE_H
#include "BaseCatcher.h"
class IMDB_by_people:public BaseCatcher{
    std::string name_args;
public:
    IMDB_by_people();

    IMDB_by_people(std::string &name);

    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_IMDB_BY_PEOPLE_H
