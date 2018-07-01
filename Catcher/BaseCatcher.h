#ifndef MICP_BASECATCHER_H
#define MICP_BASECATCHER_H
//math.h在某一个toplist中会用到
//由于按助教的ppt一开始写出的该基类，但是后期作者考虑多种因素，将很多功能移除出BaseCatcher，也就是说
//真正有用的两个函数为MakeCatcher，SaveinBaseObject
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
     
    virtual void MakeCatcher()= 0; //用来爬信息

    virtual std::ifstream SaveinBaseObject()= 0;//用来存信息，要结合BaseStrategy使用

    virtual void ExporttoDatabase()= 0;

};
#endif //MICP_BASECATCHER_H
