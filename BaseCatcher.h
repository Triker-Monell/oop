#ifndef MICP_BASECATCHER_H
#define MICP_BASECATCHER_H

#include <iostream>
#include <math.h>
#include <fstream>
#include <C:\Users\lenovo\AppData\Local\Programs\Python\Python36\include/Python.h>
#include "allHeadFiles.h"
#include "BaseObject.h"
class BaseCatcher{
    BaseObject* base_object;
    std::string name_args;
public:
    BaseCatcher();
    BaseCatcher(string &name);
    virtual ~BaseCatcher();

    virtual void SetParameter()= 0;

    virtual void  SetBaseData()= 0;

    virtual void MakeCatcher()= 0;

    virtual std::ifstream SaveinBaseObject()= 0;

    virtual void ExporttoDatabase()= 0;

};
#endif //MICP_BASECATCHER_H
