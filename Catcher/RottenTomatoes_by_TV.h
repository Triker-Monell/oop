//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_ROTTENTOMATOES_BY_TV_H
#define MICP_ROTTENTOMATOES_BY_TV_H
#include "BaseCatcher.h"
class RottenTomatoes_by_TV:public BaseCatcher{
    std::string name_args;
public:
    RottenTomatoes_by_TV();
    RottenTomatoes_by_TV(std::string &name);
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_ROTTENTOMATOES_BY_TV_H
