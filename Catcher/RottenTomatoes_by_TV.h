//
// Created by lenovo on 2018/5/29.
//

#ifndef MICP_ROTTENTOMATOES_BY_TV_H
#define MICP_ROTTENTOMATOES_BY_TV_H
#include "BaseCatcher.h"
//类的具体含义详见Catcher说明文档
//函数的功能如BaseCatcher中的说明所述
class RottenTomatoes_by_TV:public BaseCatcher{
public:
    RottenTomatoes_by_TV(){}
    void SetParameter();

    void  SetBaseData();

    void MakeCatcher();

    std::ifstream SaveinBaseObject();

    void ExporttoDatabase();
};
#endif //MICP_ROTTENTOMATOES_BY_TV_H
