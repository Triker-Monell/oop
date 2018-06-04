#include "IMDB_by_movies.h"
void IMDB_by_movies::SetParameter() {

}
void IMDB_by_movies::SetBaseData() {

}
void IMDB_by_movies::SaveinBaseObject() {
    std::ifstream readfile;
    readfile.open("IMDB_by_movies.txt",std::ios::in);
    std::string name,rating,actors,info,sites,country,language,related_movies,
            directors,runtime,date,boxing,temp;
    readfile>>temp;
    do{
        readfile>>temp;
        name+=temp;
    }while(temp!="rating:");

    readfile>>rating;
    readfile>>temp;
    do{
        readfile>>temp;
        directors+=temp;

    }while(temp!="actor:");

    do{
        readfile>>temp;
        actors+=temp;
    }while(temp!="releasedate:");
    do{
        readfile>>temp;
        date+=temp;

    }while(temp!="related:");
    readfile>>temp;

    do{
        readfile>>temp;
        related_movies+=temp;
    }while(temp!="Tagline:");

    do{
        readfile>>temp;
    }while(temp!="Sites:");
    do{
        readfile>>temp;
        sites+=temp;
    }while(temp!="See");
    do{
        readfile>>temp;

    }while(temp!="Country:");
    readfile>>country;
    readfile>>temp;
    readfile>>language;
    do{
        readfile>>temp;

    }while(temp!="Budget:");
    boxing+=temp;
    do{
        readfile>>temp;
        boxing+=temp;

    }while(temp!="See");
    do{
        readfile>>temp;
    }while(temp!="Runtime:");
    readfile>>runtime;
    readfile.close();
    fclose(fopen("IMDB_by_movies.txt","w"));
}
void IMDB_by_movies::MakeCatcher() {
    PyObject * pModule = nullptr,*pFunc = nullptr;
    PyObject * pArgs = nullptr,*pValue = nullptr;
    Py_Initialize();
    pModule = PyImport_ImportModule("IMDB_by_movies");
    pFunc = PyObject_GetAttrString(pModule, "work");
    pValue = PyObject_CallObject(pFunc,pArgs);
    Py_Finalize();
}
void IMDB_by_movies::ExporttoDatabase() {

}