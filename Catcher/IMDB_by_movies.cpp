#include "IMDB_by_movies.h"
void IMDB_by_movies::SetParameter() {

}
void IMDB_by_movies::SetBaseData() {

}
std::ifstream IMDB_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("IMDB_by_movies.txt",std::ios::in);
    return readfile;
}
void IMDB_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("IMDB_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void IMDB_by_movies::ExporttoDatabase() {

}