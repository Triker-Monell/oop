//
// Created by lenovo on 2018/5/29.
//

#include "IMDB_by_TV.h"

void IMDB_by_TV::ExporttoDatabase() {

}
void IMDB_by_TV::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("IMDB_by_TV");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void IMDB_by_TV::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("IMDB_by_TV.txt",std::ios::in);
    std::string name,rating,actors,info,sites,country,language,year,othername,related_movies,
            producers,date,temp;
    readfile>>temp;
    do{
        readfile>>temp;
        name+=temp;
    }while(temp!="rating:");

    readfile>>rating;
    readfile>>temp;
    do{
        readfile>>temp;
        actors+=temp;
    }while(temp!="releasedate:");
    do{
        readfile>>temp;
        year+=temp;

    }while(temp!="related:");
    readfile>>temp;

    do{
        readfile>>temp;
        related_movies+=temp;
    }while(temp!="The:");
    readfile>>temp;
    readfile>>temp;
    do{
        readfile>>temp;

    }while(temp!="Official");

    readfile>>temp;
    do{
        readfile>>temp;
        sites+=temp;
    }while(temp!="See");
    do{
        readfile>>temp;
    }while(temp!="Country:");

    do{
        readfile>>temp;
        country+=temp;
    }while(temp!="Language:");
    readfile>>language;
    readfile>>temp;
    readfile>>temp;
    do{
        readfile>>temp;
        date+=temp;
    }while(temp!="See");
    readfile>>temp;
    do{
        readfile>>temp;

    }while(temp!="As:");

    do{
        readfile>>temp;
        othername+=temp;
    }while(temp!="See");
    do{
        readfile>>temp;
    }while(temp!="Co:");
    do{
        readfile>>temp;
        producers+=temp;
    }while(temp!="See");
    do{
        readfile>>temp;
    }while(temp!="Runtime:");
    do{
        readfile>>temp;
        info+=temp;
    }while(!EOF);


    readfile.close();
    fclose(fopen("IMDB_by_TV.txt","w"));
}
void IMDB_by_TV::SetBaseData() {

}
void IMDB_by_TV::SetParameter() {

}