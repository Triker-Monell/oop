#ifndef MICP_BASECATCHER_H
#define MICP_BASECATCHER_H

#include <iostream>
#include <math.h>
#include <fstream>
#include "python2.7/Python.h"
#include "BaseData/path.h"
class BaseObject;
class BaseCatcher{
    BaseObject* base_object;
public:
    BaseCatcher();
    virtual ~BaseCatcher();

    virtual void SetParameter()= 0;

    virtual void  SetBaseData()= 0;

    virtual void MakeCatcher()= 0;

    virtual std::ifstream SaveinBaseObject()= 0;

    virtual void ExporttoDatabase()= 0;

};
#endif //MICP_BASECATCHER_H
