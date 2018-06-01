//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_IMDB_BY_TV_H
#define MICP_IMDB_BY_TV_H
#include "BaseCatcher.h"
class IMDB_by_TV:public BaseCatcher{
    std::string name_args;
public:
    IMDB_by_TV();
    IMDB_by_TV(std::string &name);
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_IMDB_BY_TV_H
