//
// Created by lenovo on 2018/5/29.
//

#include "RottenTomatoes_by_TV.h"

void RottenTomatoes_by_TV::ExporttoDatabase() {

}
void RottenTomatoes_by_TV::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("RottenTomatoes_by_TV");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void RottenTomatoes_by_TV::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("RottenTomatoes_by_TV.txt",std::ios::in);
    std::string name,rating,actors,info,genre,network,
            producers,date,temp;
    readfile>>temp;
    readfile>>name;
    do{
        readfile>>temp;
        rating+=temp;
    }while(temp!="Actor:");

    readfile>>temp;
    do{
        readfile>>temp;
        actors+=temp;
    }while(temp!="View");
    readfile>>temp;
    readfile>>temp;
    do{
        readfile>>temp;
        info+=temp;
    }while(temp!="Genre:");
    do{
        readfile>>temp;
        genre+=temp;

    }while(temp!="Network:");
    readfile>>network;
    readfile>>temp;
    do{
        readfile>>temp;
        date+=temp;
    }while(temp!="Producers:");

    do{
        readfile>>temp;
        producers+=temp;
    }while(temp!="Premiere:");
    readfile.close();
    fclose(fopen("RottenTomatoes_by_TV.txt","w"));
}
void RottenTomatoes_by_TV::SetBaseData() {

}
void RottenTomatoes_by_TV::SetParameter() {

}