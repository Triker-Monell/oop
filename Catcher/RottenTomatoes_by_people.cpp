//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_people.h"

void RottenTomatoes_by_people::ExporttoDatabase() {

}
void RottenTomatoes_by_people::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("RottenTomatoes_by_people");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_people::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("RottenTomatoes_by_people.txt",std::ios::in);
    return readfile;
}
void RottenTomatoes_by_people::SetBaseData() {

}
void RottenTomatoes_by_people::SetParameter() {

}