#ifndef MICP_DOUBANCATCHER_H
#define MICP_DOUBANCATCHER_H
#include "BaseCatcher.h"
class Douban_by_movies:public BaseCatcher{
    std::string name_args;
public:
    Douban_by_movies();
    Douban_by_movies(std::string &name);
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_DOUBANCATCHER_H
