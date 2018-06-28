//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_TV.h"

void RottenTomatoes_by_TV::ExporttoDatabase() {

}
void RottenTomatoes_by_TV::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/')");
    //????????

    pModule = PyImport_ImportModule("RottenTomatoes_by_TV");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_TV::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("RottenTomatoes_by_TV.txt",std::ios::in);
    return readfile;
}
void RottenTomatoes_by_TV::SetBaseData() {

}
void RottenTomatoes_by_TV::SetParameter() {

}