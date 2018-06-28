
#ifndef MICP_IBDMCATCHER_H
#define MICP_IBDMCATCHER_H

#include "BaseCatcher.h"
class IMDB_by_movies:public BaseCatcher{
public:
    IMDB_by_movies();

    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_IBDMCATCHER_H
