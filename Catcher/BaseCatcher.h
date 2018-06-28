#ifndef MICP_BASECATCHER_H
#define MICP_BASECATCHER_H

#include <iostream>
#include <math.h>
#include <fstream>
#include <C:\Python27\include\Python.h>
class BaseObject;
class BaseCatcher{
    BaseObject* base_object;
    std::string name_args;
public:
    BaseCatcher();
    BaseCatcher(std::string &name):name_args(name){};
    virtual ~BaseCatcher();

    virtual void SetParameter()= 0;

    virtual void  SetBaseData()= 0;

    virtual void MakeCatcher()= 0;

    virtual std::ifstream SaveinBaseObject()= 0;

    virtual void ExporttoDatabase()= 0;

};
#endif //MICP_BASECATCHER_H
