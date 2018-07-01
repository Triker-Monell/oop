#include "Douban_by_movies.h"
#include "BaseData/path.h"
void Douban_by_movies::ExporttoDatabase() {

}
void Douban_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");

    std::string cmd="sys.path.append('"+WORKPATH+"')";
    qDebug() << QString::fromStdString(cmd);

    PyRun_SimpleString(cmd.c_str());
    //????????

    pModule = PyImport_ImportModule("Douban_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream Douban_by_movies::SaveinBaseObject() {
    std::ifstream readfile;

    std::string path=PATH+"Douban_by_movies.txt";
    readfile.open(path.c_str(),std::ios::in);
    return readfile;

}

void Douban_by_movies::SetBaseData() {

}
void Douban_by_movies::SetParameter() {

}
