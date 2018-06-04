//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_IMDB_BY_TOPLIST_H
#define MICP_IMDB_BY_TOPLIST_H
#include "BaseCatcher.h"
class IMDB_by_toplist:public BaseCatcher{
public:
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_IMDB_BY_TOPLIST_H
