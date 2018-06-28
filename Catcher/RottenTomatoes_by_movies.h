#ifndef MICP_LANFANQIECATCHER_H
#define MICP_LANFANQIECATCHER_H

#include "BaseCatcher.h"
class RottenTomatoes_by_movies:public BaseCatcher{
public:
    RottenTomatoes_by_movies();
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_LANFANQIECATCHER_H
