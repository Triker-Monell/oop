#include "Strategies.h"


BaseStrategy::BaseStrategy() {

}

void Imdb_movies_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new IMDB_by_movies(std::string aug);
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
    delete bas;


}

void Douban_movies_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new Douban_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
    delete bas;
}

void Tomato_movies_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new RottenTomatoes_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();

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
    delete bas;

}

void Imdb_TV_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new IMDB_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
    delete bas;

}

void Douban_TV_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new Douban_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,rating,director,writter,actor,grene,
            area,language,temp,date,runtime,othername;
    int episode=0,season=0;
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
        season++;
    }while(temp!="集数:");
    season--;
    readfile>>episode;
    readfile>>temp;
    readfile>>runtime;
    readfile.close();
    fclose(fopen("Douban_by_TV.txt","w"));
    delete bas;

}

void Tomato_TV_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new RottenTomatoes_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
    delete bas;

}

void Imdb_people_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas =new IMDB_by_people();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
}

void Douban_people_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new Douban_by_people();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,sex,constellation,birthplace,birthday,jobs,othername,family,imdbnum,temp,intro;
    readfile>>temp;
    readfile>>name;
    readfile>>temp;
    readfile>>temp;
    readfile>>sex;
    readfile>>temp;
    readfile>>temp;
    readfile>>constellation;
    readfile>>temp;
    readfile>>temp;
    readfile>>birthday;
    readfile>>temp;
    readfile>>temp;
    readfile>>birthplace;
    readfile>>temp;
    readfile>>temp;
    temp="/";
    do{
        readfile>>jobs;
        readfile>>temp;
    }while(temp=="/");
    readfile>>temp;
    temp="/";
    do{
        readfile>>othername;
        readfile>>temp;
    }while(temp=="/");
    readfile>>temp;
    do{
        readfile>>temp;
        if(temp!="imdb编号");
        family+=temp;
    }while(temp!="imdb编号");
    readfile>>temp;
    readfile>>imdbnum;
    readfile>>intro;
    readfile.close();
    fclose(fopen("Douban_by_people.txt","w"));
    delete bas;

}

void Tomato_people_Strategy::exec(std::vector<BaseData> &complexData, std::vector<BaseData> &simpleData) {
    bas=new RottenTomatoes_by_people();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,born_info,jobs,main_info,temp,main_movies;
    readfile>>temp;
    readfile>>name;
    do{
        readfile>>temp;
        main_info+=temp;
    }while(temp!="Birthday:");

    readfile>>temp;
    do{
        readfile>>temp;
        born_info+=temp;
    }while(temp!="movies:");

    do{
        readfile>>temp;
        main_movies+=temp;

    }while(!EOF);
    readfile.close();
    fclose(fopen("RottenTomatoes_by_people.txt","w"));
    delete bas;
}
