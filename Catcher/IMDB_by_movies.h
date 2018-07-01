
#ifndef MICP_IBDMCATCHER_H
#define MICP_IBDMCATCHER_H

#include "BaseCatcher.h"

//类的具体含义详见Catcher说明文档
//函数的功能如BaseCatcher中的说明所述
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
