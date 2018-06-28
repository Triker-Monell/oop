#include "RottenTomatoes_by_movies.h"
void RottenTomatoes_by_movies::ExporttoDatabase() {

}
void RottenTomatoes_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("RottenTomatoes_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
std::ifstream RottenTomatoes_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("RottenTomatoes_by_movies.txt",std::ios::in);
    std::string name,rating,actors,info,genre,director,
            writter,runtime,studio,temp;
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

    }while(temp!="Directed");
    readfile>>temp;
    do{
        readfile>>temp;
        director+=temp;
    }while(temp!="Written");
    readfile>>temp;
    do{
        readfile>>temp;
        writter+=temp;
    }while(temp!="Runtime:");
    readfile>>runtime;
    readfile>>temp;
    readfile>>studio;
    readfile.close();
    fclose(fopen("RottenTomatoes_by_movies.txt","w"));
}
void RottenTomatoes_by_movies::SetBaseData() {

}
void RottenTomatoes_by_movies::SetParameter() {

}