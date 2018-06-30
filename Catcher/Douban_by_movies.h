#ifndef MICP_DOUBANCATCHER_H
#define MICP_DOUBANCATCHER_H
#include "BaseCatcher.h"
class Douban_by_movies:public BaseCatcher{
public:
    Douban_by_movies(){}
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_DOUBANCATCHER_H
