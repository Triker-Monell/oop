#ifndef MICP_LANFANQIECATCHER_H
#define MICP_LANFANQIECATCHER_H

#include "BaseCatcher.h"
class RottenTomatoes_by_movies:public BaseCatcher{
    std::string name_args;
public:
    RottenTomatoes_by_movies();
    RottenTomatoes_by_movies(std::string &name);
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    void SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_LANFANQIECATCHER_H
