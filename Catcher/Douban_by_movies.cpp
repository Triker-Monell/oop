#include "Douban_by_movies.h"
void Douban_by_movies::ExporttoDatabase() {

}
void Douban_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("Douban_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream Douban_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("Douban_by_movies.txt",std::ios::in);
    return readfile;

}

void Douban_by_movies::SetBaseData() {

}
void Douban_by_movies::SetParameter() {

}