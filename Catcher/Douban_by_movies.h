#ifndef MICP_DOUBANCATCHER_H
#define MICP_DOUBANCATCHER_H

//类的具体含义详见Catcher说明文档
//函数的功能如BaseCatcher中的说明所述
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
