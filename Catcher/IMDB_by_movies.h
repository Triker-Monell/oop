
#ifndef MICP_IBDMCATCHER_H
#define MICP_IBDMCATCHER_H

#include "BaseCatcher.h"
class IMDB_by_movies:public BaseCatcher{
    std::string name_args;
public:
    IMDB_by_movies();
    IMDB_by_movies(std::string &name);

    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_IBDMCATCHER_H
