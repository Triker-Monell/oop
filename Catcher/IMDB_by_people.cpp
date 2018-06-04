//
// Created by lenovo on 2018/5/29.
//

#include "IMDB_by_people.h"

void IMDB_by_people::ExporttoDatabase() {

}
void IMDB_by_people::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("IMDB_by_people");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void IMDB_by_people::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("IMDB_by_people.txt",std::ios::in);
    std::string name,born_info,jobs,main_movies,temp;
    readfile>>name;
    do{
        readfile>>temp;
    }while(temp!="Born:");
    do{
        readfile>>temp;
        born_info+=temp;

    }while(temp!="job:");
    readfile>>jobs;
    readfile>>temp;
    do{
        readfile>>temp;
        main_movies+=temp;
    }while(!EOF);
    fclose(fopen("IMDB_by_people.txt","w"));
    SetName(name);
    SetJobs(jobs);
    Setborn_info(born_info);
    Setmain_movies(main_movies);
}
void IMDB_by_people::SetBaseData() {

}
void IMDB_by_people::SetParameter() {

}