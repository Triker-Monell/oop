#include "Strategies.h"
#include "allBaseData.h"
#include "allObj.h"
#include "allCatcher.h"
BaseStrategy::BaseStrategy() {

}

void BaseStrategy::initialTXT(std::string _filename, std::string _name) {
    std::ofstream outf;
    outf.open(_filename);
    outf<<_name<<std::endl;
    outf.close();
}

void Imdb_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    initialTXT("IMDB_by_movies.txt",_name);
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
    Input* ins= new IMDBSinput;
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
    simpleData.push_back(_info);
    simpleData.push_back(_sites);
    simpleData.push_back(_country);
    simpleData.push_back(_language);
    simpleData.push_back(_runtime);
    simpleData.push_back(_date);
    simpleData.push_back(_boxing);
    simpleData.push_back(_rating);

}

void Douban_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("Douban_by_movies.txt",_name);

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
    Input* in=new stdInput;
    Input* ins=new DBSinput;

    BaseData* _moviename=new MovieName();
    BaseData* _rating=new DouBanScore();
    BaseData* _director=new Director();
    BaseData* _writter=new Writer();
    BaseData* _actor=new LeadingActor();
    BaseData* _grene=new Type();
    BaseData* _area=new FilmMakingArea();
    BaseData* _language=new Language();
    BaseData* _date=new ReleaseDate();
    BaseData* _runtime=new Runtime();

    _moviename->setData(name,in);
    _moviename->setData(othername,in);
    _rating->setData(rating,ins);
    _director->setData(director,in);
    _writter->setData(writter,in);
    _actor->setData(actor,in);
    _grene->setData(grene,in);
    _area->setData(area,in);
    _language->setData(language,in);
    _date->setData(date,in);
    _runtime->setData(runtime,in);

    complexData.push_back(_director);
    complexData.push_back(_actor);
    complexData.push_back(_writter);
    simpleData.push_back(_moviename);
    simpleData.push_back(_grene);
    simpleData.push_back(_area);
    simpleData.push_back(_language);
    simpleData.push_back(_date);
    simpleData.push_back(_runtime);
    simpleData.push_back(_rating);


}

void Tomato_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("RottenTomatoes_by_movies.txt",_name);

    bas=new RottenTomatoes_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();

    std::string name,rating,actors,info,gnere,director,
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
        gnere+=temp;

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
    Input* in=new stdInput;
    Input* ins=new RTSinput;


    BaseData* _moviename=new MovieName();
    BaseData* _rating =new RottenTomatoesScore();
    BaseData* _actor=new LeadingActor();
    BaseData* _info=new Intro();
    BaseData* _grene=new Type();
    BaseData* _director=new Director();
    BaseData* _writter=new Writer();
    BaseData* _runtime=new Runtime();
    BaseData* _studio=new Studio();

    _moviename->setData(name,in);
    _rating->setData(rating,ins);
    _actor->setData(actors,in);
    _info->setData(info,in);
    _grene->setData(gnere,in);
    _director->setData(director,in);
    _writter->setData(writter,in);
    _runtime->setData(runtime,in);
    _studio->setData(studio,in);

    complexData.push_back(_actor);
    complexData.push_back(_director);
    complexData.push_back(_writter);
    simpleData.push_back(_moviename);
    simpleData.push_back(_info);
    simpleData.push_back(_grene);
    simpleData.push_back(_runtime);
    simpleData.push_back(_studio);
    simpleData.push_back(_rating);



}

void Imdb_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("IMDB_by_TV.txt",_name);

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
    Input* in=new stdInput;
    Input* ins=new IMDBSinput;

    BaseData* _TVname=new TVplayName();
    BaseData* _rating=new IMDBScore();
    BaseData* _actor=new LeadingActor();
    BaseData* _info=new Intro();
    BaseData* _sites=new OfficialSites();
    BaseData* _country=new FilmMakingArea();
    BaseData* _language=new Language();
    BaseData* _year=new ReleaseDate();
    BaseData* _related_movies=new SimilarMovie();
    BaseData* _producers=new Director();
    BaseData* _date=new ReleaseDate();

    _TVname->setData(name,in);
    _TVname->setData(othername,in);
    _rating->setData(rating,ins);
    _actor->setData(actors,in);
    _info->setData(info,in);
    _sites->setData(sites,in);
    _country->setData(country,in);
    _language->setData(language,in);
    _year->setData(year,in);
    _related_movies->setData(related_movies,in);
    _producers->setData(producers,in);
    _date->setData(date,in);

    complexData.push_back(_actor);
    complexData.push_back(_producers);
    complexData.push_back(_related_movies);
    simpleData.push_back(_TVname);
    simpleData.push_back(_info);
    simpleData.push_back(_sites);
    simpleData.push_back(_country);
    simpleData.push_back(_language);
    simpleData.push_back(_year);
    simpleData.push_back(_date);
    simpleData.push_back(_rating);

}

void Douban_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("Douban_by_TV.txt",_name);

    bas=new Douban_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,rating,director,actor,writter,grene,
            area,language,temp,date,runtime;
    int episode=0,season=1;
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
    Input* in=new stdInput;
    Input* ins=new DBSinput;

    BaseData* _TVname=new TVplayName();
    BaseData* _rating=new DouBanScore();
    BaseData* _director=new Director();
    BaseData* _actor=new LeadingActor();
    BaseData* _writter=new Writer();
    BaseData* _grene=new Type();
    BaseData* _area=new FilmMakingArea();
    BaseData* _language=new Language();
    BaseData* _date=new ReleaseDate();
    BaseData* _runtime=new Runtime();
    BaseData* _episode=new Episodes();
    BaseData* _season=new Season();

    _TVname->setData(name,in);
    _rating->setData(rating,ins);
    _director->setData(director,in);
    _actor->setData(actor,in);
    _writter->setData(writter,in);
    _grene->setData(grene,in);
    _area->setData(area,in);
    _language->setData(language,in);
    _date->setData(date,in);
    _runtime->setData(runtime,in);
    _episode->setData(static_cast<char*>(episode),in);
    _season->setData(static_cast<char*>(season),in);

    complexData.push_back(_actor);
    complexData.push_back(_writter);
    complexData.push_back(_director);
    simpleData.push_back(_TVname);
    simpleData.push_back(_grene);
    simpleData.push_back(_area);
    simpleData.push_back(_language);
    simpleData.push_back(_date);
    simpleData.push_back(_runtime);
    simpleData.push_back(_episode);
    simpleData.push_back(_season);
}

void Tomato_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("RottenTomatoes_by_TV.txt",_name);

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


    Input* in=new stdInput;
    Input* ins=new RTSinput;
    BaseData*_TVname=new TVplayName();
    BaseData*_rating=new RottenTomatoesScore();
    BaseData*_actors=new Intro();
    BaseData*_genre=new Type();
    BaseData*_network=new Studio();
    BaseData*_producers=new Director();
    BaseData*_date=new ReleaseDate();
    BaseData*_info=new Intro();

    _TVname->setData(name,in);
    _rating->setData(rating,in);
    _actors->setData(actors,in);
    _genre->setData(genre,in);
    _network->setData(network,in);
    _producers->setData(producers,in);
    _date->setData(date,in);
    _info->setData(info,in);

    complexData.push_back(_actors);
    complexData.push_back(_producers);
    simpleData.push_back(_TVname);
    simpleData.push_back(_network);
    simpleData.push_back(_date);
    simpleData.push_back(_info);
    simpleData.push_back(_genre);
    simpleData.push_back(_rating);


}

void Imdb_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("IMDB_by_people.txt",_name);

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

    Input* in=new stdInput;
    BaseData*_peoplename =new PersonName();
    BaseData*_born_info=new Intro();
    BaseData*_jobs=new Job();
    BaseData*_main_movies=new MovieName();

    _peoplename->setData(name,in);
    _born_info->setData(born_info,in);
    _jobs->setData(jobs,in);
    _main_movies->setData(main_movies,in);

    complexData.push_back(_main_movies);
    simpleData.push_back(_peoplename);
    simpleData.push_back(_born_info);
    simpleData.push_back(_jobs);

}

void Douban_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    initialTXT("Douban_by_people.txt",_name);

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


    Input* in =new stdInput;
    BaseData*_peoplename=new PersonName();
    BaseData*_sex=new Sex();
    BaseData*_constellation=new Constellation();
    BaseData*_birthplace=new BirthPlace();
    BaseData*_birthday=new BirthDate();
    BaseData*_jobs=new Job();
    BaseData*_family=new Family();
    BaseData*_imdbnum=new Imdbnum();
    BaseData*_intro=new Intro();

    _peoplename->setData(name,in);
    _sex->setData(sex,in);
    _constellation->setData(constellation,in);
    _birthday->setData(birthday,in);
    _birthplace->setData(birthplace,in);
    _jobs->setData(jobs,in);
    _family->setData(family,in);
    _imdbnum->setData(imdbnum,in);
    _intro->setData(intro,in);

    simpleData.push_back(_peoplename);
    simpleData.push_back(_sex);
    simpleData.push_back(_constellation);
    simpleData.push_back(_birthday);
    simpleData.push_back(_birthplace);
    simpleData.push_back(_jobs);
    simpleData.push_back(_family);
    simpleData.push_back(_imdbnum);
    simpleData.push_back(_intro);



}

void Tomato_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    initialTXT("RottenTomatoes_by_people.txt", _name);

    bas = new RottenTomatoes_by_people();
    bas->MakeCatcher();
    std::ifstream readfile = bas->SaveinBaseObject();
    std::string name, born_info, jobs, main_info, temp, main_movies;
    readfile >> temp;
    readfile >> name;
    do {
        readfile >> temp;
        main_info += temp;
    } while (temp != "Birthday:");

    readfile >> temp;
    do {
        readfile >> temp;
        born_info += temp;
    } while (temp != "movies:");

    do {
        readfile >> temp;
        main_movies += temp;

    } while (!EOF);
    readfile.close();
    fclose(fopen("RottenTomatoes_by_people.txt", "w"));

    Input *in = new stdInput;

    BaseData *_peoplename = new PersonName();
    BaseData *_born_info = new BirthPlace();
    BaseData *_jobs = new Job();
    BaseData *_main_info = new Intro();
    BaseData *_main_movies = new MovieName();

    _peoplename->setData(name, in);
    _born_info->setData(born_info, in);
    _jobs->setData(jobs, in);
    _main_info->setData(main_info, in);
    _main_movies->setData(main_movies, in);

    complexData.push_back(_main_movies);
    simpleData.push_back(_peoplename);
    simpleData.push_back(_born_info);
    simpleData.push_back(_jobs);
    simpleData.push_back(_main_info);

    delete bas;
}