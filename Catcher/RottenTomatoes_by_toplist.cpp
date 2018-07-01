//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_toplist.h"

void RottenTomatoes_by_toplist::ExporttoDatabase() {

}
void RottenTomatoes_by_toplist::MakeCatcher() {
    //该部分为使用C++中的python指针调用py工作
    //每个函数只有在PyImport_ImportModule时不同，每个去调用名称对应的xxx.py
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");

    std::string cmd="sys.path.append('"+WORKPATH+"')";
    qDebug() << QString::fromStdString(cmd);

    PyRun_SimpleString(cmd.c_str());
     

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
