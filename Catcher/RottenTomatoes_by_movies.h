#ifndef MICP_LANFANQIECATCHER_H
#define MICP_LANFANQIECATCHER_H

#include "BaseCatcher.h"

//类的具体含义详见Catcher说明文档
//函数的功能如BaseCatcher中的说明所述
class RottenTomatoes_by_movies:public BaseCatcher{
public:
    RottenTomatoes_by_movies(){}
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_LANFANQIECATCHER_H
