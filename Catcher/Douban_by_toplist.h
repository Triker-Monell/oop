//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_DOUBAN_BY_TOPLIST_H
#define MICP_DOUBAN_BY_TOPLIST_H
#include "BaseCatcher.h"
class Douban_by_toplist:public BaseCatcher{
public:
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_DOUBAN_BY_TOPLIST_H
