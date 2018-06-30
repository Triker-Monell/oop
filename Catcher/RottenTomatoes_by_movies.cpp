#include "RottenTomatoes_by_movies.h"
void RottenTomatoes_by_movies::ExporttoDatabase() {

}
void RottenTomatoes_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/')");
    //????????

    pModule = PyImport_ImportModule("RottenTomatoes_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("RottenTomatoes_by_movies.txt",std::ios::in);
    std::ofstream("RottenTomatoes_by_movies.txt",std::ios::trunc);
    return readfile;
}
void RottenTomatoes_by_movies::SetBaseData() {

}
void RottenTomatoes_by_movies::SetParameter() {

}
