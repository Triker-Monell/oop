//
// Created by lenovo on 2018/5/29.
//

#include "IMDB_by_toplist.h"

void Douban_by_movies::ExporttoDatabase() {

}
void IMDB_by_toplist::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
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