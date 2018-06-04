//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_DOUBAN_BY_TV_H
#define MICP_DOUBAN_BY_TV_H
#include "BaseCatcher.h"
class Douban_by_TV:public BaseCatcher{
    std::string name_args;
public:
    Douban_by_TV();
    Douban_by_TV(std::string &name);
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_DOUBAN_BY_TV_H
