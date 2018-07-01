//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_people.h"

void RottenTomatoes_by_people::ExporttoDatabase() {

}
void RottenTomatoes_by_people::MakeCatcher() {
    //该部分为使用C++中的python指针调用py工作
    //每个函数只有在PyImport_ImportModule时不同，每个去调用名称对应的xxx.py
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/Catcher')");
    

    pModule = PyImport_ImportModule("RottenTomatoes_by_people");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_people::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_people.txt",std::ios::in);
    return readfile;
}
void RottenTomatoes_by_people::SetBaseData() {

}
void RottenTomatoes_by_people::SetParameter() {

}
