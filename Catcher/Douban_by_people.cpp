#include"Douban_by_people.h"

void Douban_by_people::ExporttoDatabase() {

}
void Douban_by_people::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("Douban_by_people");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void Douban_by_people::SaveinBaseObject() {

}
void Douban_by_people::SetBaseData() {

}
void Douban_by_people::SetParameter() {

}