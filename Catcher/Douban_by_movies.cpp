#include "Douban_by_movies.h"
void Douban_by_movies::ExporttoDatabase() {

}
void Douban_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    //该部分为使用C++中的python指针调用py工作
    //每个函数只有在PyImport_ImportModule时不同，每个去调用名称对应的xxx.py
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/Catcher/')");
     

    pModule = PyImport_ImportModule("Douban_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream Douban_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_movies.txt",std::ios::in);
    return readfile;

}

void Douban_by_movies::SetBaseData() {

}
void Douban_by_movies::SetParameter() {

}
