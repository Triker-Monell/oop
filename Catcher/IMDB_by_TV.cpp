//
// Created by lenovo on 2018/5/29.
//

#include "IMDB_by_TV.h"
#include "BaseData/path.h"
void IMDB_by_TV::ExporttoDatabase() {

}
void IMDB_by_TV::MakeCatcher() {
    //该部分为使用C++中的python指针调用py工作
    //每个函数只有在PyImport_ImportModule时不同，每个去调用名称对应的xxx.py
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");

    std::string cmd="sys.path.append('"+WORKPATH+"')";
    qDebug() << QString::fromStdString(cmd);

    PyRun_SimpleString(cmd.c_str());
   

    pModule = PyImport_ImportModule("IMDB_by_TV");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream IMDB_by_TV::SaveinBaseObject() {
    std::ifstream readfile;

    std::string path=PATH+"IMDB_by_TV.txt";

    readfile.open(path.c_str(),std::ios::in);
    return readfile;
}
void IMDB_by_TV::SetBaseData() {

}
void IMDB_by_TV::SetParameter() {

}
