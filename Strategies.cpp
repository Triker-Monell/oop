#include "Strategies.h"
#include "BaseData/BaseData.h"
#include "BaseData/Date.h"
#include "BaseData/Director.h"
#include "BaseData/DouBanScore.h"
#include "BaseData/Episodes.h"
#include "BaseData/Image.h"
#include "BaseData/IMDBScore.h"
#include "BaseData/Language.h"
#include "BaseData/LeadingActor.h"
#include "BaseData/Name.h"
#include "BaseData/People.h"
#include "BaseData/Place.h"
#include "BaseData/Rated.h"
#include "BaseData/RottenTomatoesScore.h"
#include "BaseData/Runtime.h"
#include "BaseData/Score.h"
#include "BaseData/Similar.h"
#include "BaseData/Type.h"
#include "BaseData/Writer.h"
#include "BaseData/OfficialSites.h"
#include "BaseData/Boxing.h"
#include "BaseData/Intro.h"

BaseStrategy::BaseStrategy() {

}

void Imdb_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    std::ofstream outf;
    outf.open("IMDB_by_movies.txt");
    outf<<_name<<std::endl;
    outf.close();
    bas=new IMDB_by_movies();
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
    Input* in =new stdInput;
    Input* ins= new IMDBSInput;
    BaseData* _moviename=new MovieName();
    BaseData* _rating=new IMDBScore();
    BaseData*_actors=new LeadingActor();
    BaseData*_info=new Intro();
    BaseData*_sites=new OfficialSites();
    BaseData*_country=new FilmMakingArea();
    BaseData*_language=new Language();
    BaseData*_related_movies=new SimilarMovie();
    BaseData*_directors=new Director();
    BaseData*_runtime=new Runtime();
    BaseData*_date=new ReleaseDate();
    BaseData*_boxing=new Boxing();
    _moviename->setData(name,in);
    _rating->setData(rating,ins);
    _actors->setData(actors,in);
    _info->setData(info,in);
    _sites->setData(sites,in);
    _country->setData(country,in);
    _language->setData(language,in);
    _related_movies->setData(related_movies,in);
    _directors->setData(directors,in);
    _runtime->setData(runtime,in);
    _date->setData(date,in);
    _boxing->setData(boxing,in);


    complexData.push_back(_directors);
    complexData.push_back(_actors);
    complexData.push_back(_related_movies);
    simpleData.push_back(_moviename);
    simpleData.push_back(_rating);
    simpleData.push_back(_info);
    simpleData.push_back(_sites);
    simpleData.push_back(_country);
    simpleData.push_back(_language);
    simpleData.push_back(_runtime);
    simpleData.push_back(_date);
    simpleData.push_back(_boxing);

}

void Douban_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("Douban_by_movies.txt");
    outf<<_name<<std::endl;
    outf.close();
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

void Tomato_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("RottenTomatoes_by_movies.txt");
    outf<<_name<<std::endl;
    outf.close();
    bas=new RottenTomatoes_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();

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
    delete bas;

}

void Imdb_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("IMDB_by_TV.txt");
    outf<<_name<<std::endl;
    outf.close();
    bas=new IMDB_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
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
    delete bas;

}

void Douban_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("Douban_by_TV.txt");
    outf<<_name<<std::endl;
    outf.close();
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

void Tomato_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("RottenTomatoes_by_TV.txt");
    outf<<_name<<std::endl;
    outf.close();
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

void Imdb_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("IMDB_by_people.txt");
    outf<<_name<<std::endl;
    outf.close();
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

void Douban_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    std::ofstream outf;
    outf.open("Douban_by_people.txt");
    outf<<_name<<std::endl;
    outf.close();
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

void Tomato_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::ofstream outf;
    outf.open("RottenTomatoes_by_people.txt");
    outf<<_name<<std::endl;
    outf.close();
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
