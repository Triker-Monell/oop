//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_toplist.h"

void RottenTomatoes_by_toplist::ExporttoDatabase() {

}
void RottenTomatoes_by_toplist::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/')");
    //????????

    pModule = PyImport_ImportModule("RottenTomatoes_by_toplist");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_toplist::SaveinBaseObject() {

}
void RottenTomatoes_by_toplist::SetBaseData() {

}
void RottenTomatoes_by_toplist::SetParameter() {

}