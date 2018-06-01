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
void Douban_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("Douban_by_movies.txt",std::ios::in);
    std::string name,rating,director,writter,actor,grene,
            area,language,temp,date,runtime,othername;
    readfile>>temp;
    readfile>>name;
    readfile>>temp;
    readfile>>temp;
    readfile>>director;
    readfile>>temp;
    readfile>>temp;
    readfile>>writter;
    readfile>>temp;
    readfile>>temp;
    do{
        readfile>>temp;
        actor+=temp;
    }while(temp!="类型：");
    do{
        readfile>>temp;
        grene+=temp;
    }while(temp!="制片国家/地区：");
    readfile>>area;
    readfile>>temp;
    readfile>>language;
    readfile>>temp;
    readfile>>date;
    readfile>>temp;
    readfile>>runtime;
    readfile>>temp;
    do{
        readfile>>temp;
        othername+=temp;
    }while(temp!="IMDB链接：");
    readfile.close();
    fclose(fopen("Douban_by_movies.txt","w"));


}

void Douban_by_movies::SetBaseData() {

}
void Douban_by_movies::SetParameter() {

}