//
// Created by lenovo on 2018/5/29.
//
#include "BaseData/path.h"
#include "IMDB_by_toplist.h"

void IMDB_by_toplist::ExporttoDatabase() {

}
void IMDB_by_toplist::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");

    std::string cmd="sys.path.append('"+WORKPATH+"')";
    qDebug() << QString::fromStdString(cmd);

    PyRun_SimpleString(cmd.c_str());
    //????????

    pModule = PyImport_ImportModule("IMDB_by_toplist");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream IMDB_by_toplist::SaveinBaseObject() {

}
void IMDB_by_toplist::SetBaseData() {

}
void IMDB_by_toplist::SetParameter() {

}
