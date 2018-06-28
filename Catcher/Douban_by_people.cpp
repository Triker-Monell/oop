#include"Douban_by_people.h"

void Douban_by_people::ExporttoDatabase() {

}
void Douban_by_people::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/monell/qtcode/InfoCS/')");
    //????????

    pModule = PyImport_ImportModule("Douban_by_people");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream Douban_by_people::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("Douban_by_people.txt",std::ios::in);
    return readfile;
}
void Douban_by_people::SetBaseData() {

}
void Douban_by_people::SetParameter() {

}