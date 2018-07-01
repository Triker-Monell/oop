//
// Created by lenovo on 2018/5/29.
//

#include "Douban_by_TV.h"

void Douban_by_TV::ExporttoDatabase() {

}
void Douban_by_TV::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/Catcher/')");
    //????????

    pModule = PyImport_ImportModule("Douban_by_TV");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream Douban_by_TV::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_TV.txt",std::ios::in);
    return readfile;
}
void Douban_by_TV::SetBaseData() {

}
void Douban_by_TV::SetParameter() {

}
