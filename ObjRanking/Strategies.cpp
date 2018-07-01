#include "Strategies.h"
#include "BaseData/allBaseData.h"
#include "allObj.h"
#include "Catcher/allCatcher.h"
#include <QDebug>
BaseStrategy::BaseStrategy() {

}

void BaseStrategy::initialTXT(std::string _filename, std::string _name) {
    std::ofstream outf;
    outf.open(_filename.c_str());
    outf<<_name<<std::endl;
    outf.close();
}

void Imdb_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    std::string path=PATH+"IMDB_by_movies.txt";
    initialTXT(path,_name);
    bas=new IMDB_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,rating,actors,info,sites,country,language,related_movies,
            directors,runtime,date,boxing,temp;
    readfile>>temp;
    readfile>>temp;
    while(temp!="rating:"){
        name+=temp;
        readfile>>temp;
    }

    readfile>>rating;
    readfile>>temp;
    readfile>>temp;
    while(temp!="actor:"){
        directors+=temp;
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="releasedate:"){
        actors+=temp;
        actors+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="relatedmovies:"){
        date+=temp;
        date+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    int i=0;
    while(temp!="Taglines:"&&i!=5){
        related_movies+=temp;
        related_movies+=" ";
        readfile>>temp;
        if(temp=="/")++i;
    }

    while(temp!="Sites:"){
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="See"&&temp!="Country:"){
        sites+=temp;
        sites+=" ";
        readfile>>temp;
    }

    while(temp!="Country:"){
        readfile>>temp;
    }
    readfile>>country;
    readfile>>temp;
    readfile>>language;
    do{
        readfile>>temp;

    }while(temp!="Worldwide");

    readfile>>temp;
    readfile>>temp;
    while(temp!="See"){
        boxing+=temp;
        boxing+=" ";
        readfile>>temp;

    };
    do{
        readfile>>temp;
    }while(temp!="Runtime:");
    readfile>>runtime;
    readfile.close();
    fclose(fopen(path.c_str(),"w"));

    Input* in =new stdInput;
    Input* ins= new IMDBSinput;
    BaseData* _moviename=new MovieName();
    BaseData* _rating=new IMDBScore();
    BaseData*_actors=new LeadingActor();
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
    simpleData.push_back(_sites);
    simpleData.push_back(_country);
    simpleData.push_back(_language);
    simpleData.push_back(_runtime);
    simpleData.push_back(_date);
    simpleData.push_back(_boxing);
    simpleData.push_back(_rating);

        delete bas;
}

void Douban_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    //样例ok

    std::string path=PATH+"Douban_by_movies.txt";
    initialTXT(path,_name);

     bas=new Douban_by_movies();
     bas->MakeCatcher();
     std::ifstream readfile=bas->SaveinBaseObject();
     std::string name,rating,director,writter,actor,grene,   //grene 类型  //area国家地区
             area,language,temp,date,runtime,othername;

     //new version : begin from here!
     bool delim = false;  //上个字符是 ‘/’   因为只能录入连续的一个‘/’

     readfile>>temp;   //"电影名"
     readfile>>name;   //名称
     readfile>>temp;readfile>>temp;readfile>>temp;readfile>>temp;readfile>>temp;readfile>>temp; //temp*6

     readfile>>director;
     readfile>>temp;
     delim = (temp == "/");
     while(temp != "编剧"){
       if(! (delim && (temp == "/"))){
         director += temp;
       }
       readfile>>temp;
       delim = (temp == "/");
     } // 编剧 跳出

     readfile>>temp;readfile>>temp;readfile>>temp;  //*3

     readfile>>writter;
     readfile>>temp;
     delim = (temp == "/");
     while(temp != "主演"){
       if(! (delim && (temp == "/"))){
         writter += temp;
       }
       readfile>>temp;
       delim = (temp == "/");
     } // 主演 跳出

     readfile>>temp;readfile>>temp;readfile>>temp; //*3

     readfile>>actor;
     actor += '/';
     readfile>>temp;
     while(temp != "类型:"){
       if(temp!="/"){
         actor = actor+temp+'/';
       }
       readfile>>temp;
     } // 类型: 跳出

     readfile>>grene;
     grene += '/';
     readfile>>temp;

     while((temp != "制片国家/地区:") && (temp != "官方网站:")){
       if(temp!="/"){
         grene = grene + temp +'/';
       }
       readfile>>temp;
     } // 制片国家/地区:  或者  官方网站:  跳出

     if( temp == "官方网站:"){
       readfile>>temp; readfile>>temp;readfile>>temp;
       readfile>>temp;
     }

     readfile>>area;
     area += '/';
     readfile>>temp;
     while(temp != "语言:"){
       if(temp!="/"){
         area = area + temp +'/';
       }
       readfile>>temp;
     } // 语言: 跳出


     readfile>>language;
     language += '/';
     readfile>>temp;
     while(temp != "上映日期:"){
       if(temp!="/"){
         language = language + temp + '/';
       }
       readfile>>temp;
     } // 上映日期: 跳出


     readfile>>date;   //上映日期
     date += '/';
     readfile>>temp;
     while(temp != "片长:"){
       if(temp!="/"){
         date = date + temp +'/';
       }
       readfile>>temp;
     } // 片长: 跳出

     readfile>>runtime;
     runtime += '/';
     readfile>>temp;
     while(temp != "又名:"){
       if(temp!="/"){
         runtime += runtime + temp +'/';
       }
       readfile>>temp;
     } // 又名: 跳出

     readfile>>othername;
     othername += '/';
     readfile>>temp;
     while(temp != "IMDb链接:"){
       if(temp != "/"){
         othername = othername + temp + '/';
       }
       readfile>>temp;
     } // IMDb链接: 跳出

     do{
       readfile>>temp;
     }while(temp != "评分:");
     readfile>>rating;

     readfile>>temp;readfile>>temp;readfile>>temp;
     readfile>>temp;
     rating = rating+' '+temp;  //5star

     readfile>>temp;readfile>>temp;
     rating = rating+' '+temp;

     readfile>>temp;readfile>>temp;
     rating = rating+' '+temp;

     readfile>>temp;readfile>>temp;
     rating = rating+' '+temp;

     readfile>>temp;readfile>>temp;
     rating = rating+' '+temp;    //1star

     /*
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
     */
     readfile.close();
     fclose(fopen(path.c_str(),"w"));
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

     _moviename->setData(name+othername,in);

     _rating->setData(rating,ins);
     _director->setData(director,in);
     _writter->setData(writter,in);
     _actor->setData(actor,in);
     _grene->setData(grene,in);
     _area->setData(area,in);
     _language->setData(language,in);
     _date->setData(date,in);
     _runtime->setData(runtime,in);

     simpleData.push_back(_moviename);
     simpleData.push_back(_director);
     simpleData.push_back(_actor);
     simpleData.push_back(_writter);
     simpleData.push_back(_grene);
     simpleData.push_back(_area);
     simpleData.push_back(_language);
     simpleData.push_back(_date);
     simpleData.push_back(_runtime);
     simpleData.push_back(_rating);



}

void Tomato_movies_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::string path=PATH+"RottenTomatoes_by_movies.txt";

    initialTXT(path,_name);

    bas=new RottenTomatoes_by_movies();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();

    std::string name,rating,actors,info,gnere,director,
            writter,runtime,studio,temp;
    readfile>>temp;
    readfile>>temp;
    while (temp!="|"){
        name+=temp;
        name+=" ";
        readfile>>temp;
    }
    while(temp!="Fresh:"){
        readfile>>temp;
    }
    readfile>>rating;
    while(temp!="Average"){

        readfile>>temp;
    }
    readfile>>temp;
    rating+=" ";
    rating+=temp;
    readfile>>temp;
    readfile>>temp;
    while(temp!="View"){
        actors+=temp;
        actors+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    readfile>>temp;
    readfile>>temp;
    while(temp!="Genre:"){
        info+=temp;
        info+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    while(temp!="Directed"){
        gnere+=temp;
        gnere+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    readfile>>temp;
    while(temp!="Written"){
        director+=temp;
        director+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    readfile>>temp;
    while(temp!="On"){
        writter+=temp;
        writter+=" ";
        readfile>>temp;
    }
    while(temp!="Runtime:"){
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="Studio:"){
        runtime+=temp;
        runtime+=" ";
        readfile>>temp;
    }
    while(readfile>>temp){
        studio+=temp;
        studio+=" ";
    }

    readfile.close();

    fclose(fopen(path.c_str(),"w"));

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


    delete bas;

}

void Imdb_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    //样例ok！！！
    std::string path=PATH+"IMDB_by_TV.txt";
    initialTXT(path,_name);

    bas=new IMDB_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,rating,actors,info,sites,country,language,year,othername,related_movies,
            producers,date,temp,runtime;
    readfile>>temp;
    readfile>>temp;
    while(temp!="rating:"){
        name+=temp;
        name+=" ";
        readfile>>temp;
    }

    readfile>>rating;
    readfile>>temp;
    readfile>>temp;
    while(temp!="releasedate:"){
        actors+=temp;
        actors+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="relatedTVs:"){
        year+=temp;
        readfile>>temp;

    }
    readfile>>temp;

    int i=0;
    while(temp!="Taglines:"&&i!=5){
        related_movies+=temp;
        related_movies+=" ";
        readfile>>temp;
        if(temp=="/")++i;
    }
    readfile>>temp;
    readfile>>temp;
    do{
        readfile>>temp;

    }while(temp!="Official");

    readfile>>temp;
    readfile>>temp;


    while(temp!="See"){
        sites+=temp;
        sites+=" ";
        readfile>>temp;
    }
    do{
        readfile>>temp;
    }while(temp!="Country:");

    readfile>>temp;
    while(temp!="Language:"){
        country+=temp;
        country+=" ";
        readfile>>temp;

    }
    readfile>>language;
    readfile>>temp;
    readfile>>temp;
    readfile>>temp;
    while(temp!="See"){
        date+=temp;
        date+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    do{
        readfile>>temp;

    }while(temp!="As:");

    readfile>>temp;
    while(temp!="See"){
        othername+=temp;
        othername+=" ";
        readfile>>temp;

    }
    do{
        readfile>>temp;
    }while(temp!="Co:");
    while(temp!="See"){
        producers+=temp;
        producers+=" ";
        readfile>>temp;
    }
    do{
        readfile>>temp;
    }while(temp!="Runtime:");
    readfile>>runtime;
    runtime+=" min";
    readfile>>temp;
    while(readfile>>temp){

        info+=temp;
        info+=" ";
    }

    readfile.close();
    fclose(fopen(path.c_str(),"w"));
    delete bas;
    Input* in=new stdInput;
    Input* ins=new IMDBSinput;

    BaseData* _TVname=new TVplayName();
    BaseData* _rating=new IMDBScore();//!!!
    BaseData* _actor=new LeadingActor();
    BaseData* _info=new Intro();
    BaseData* _sites=new OfficialSites();
    BaseData* _country=new FilmMakingArea();
    BaseData* _language=new Language();
    BaseData* _year=new ReleaseDate();
    BaseData* _related_movies=new SimilarMovie();
    BaseData* _producers=new Producer();
    BaseData* _date=new ReleaseDate();
    BaseData* _runtime=new Runtime();


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
    _runtime->setData(runtime,in);

    complexData.push_back(_actor);
    complexData.push_back(_related_movies);
    simpleData.push_back(_TVname);
    simpleData.push_back(_info);
    simpleData.push_back(_sites);
    simpleData.push_back(_country);
    simpleData.push_back(_language);
    simpleData.push_back(_year);
    simpleData.push_back(_date);
    simpleData.push_back(_runtime);
    simpleData.push_back(_producers);

    simpleData.push_back(_rating);//!!score

}

void Douban_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    //样例ok
    std::string path=PATH+"Douban_by_TV.txt";
    initialTXT(path,_name);

    bas=new Douban_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,rating,director,actor,writter,grene,
            area,language,temp,date,runtime,episode;
    int season=-1;

    readfile>>temp;    //电视名：
    readfile>>name;    //名字
    readfile>>temp;    //二十一季

    while(temp!="评分:"){
        readfile>>temp;   //rubbish
    }

    readfile>>rating;    //6 nums 空格隔开
    readfile>>temp;
    while(temp!="5星"){
        readfile>>temp;   //rubbish
    }

    readfile>>temp;   //5
    rating = rating + ' ' + temp;

    readfile>>temp;  readfile>>temp;
    rating = rating + ' ' + temp;   //4

    readfile>>temp;  readfile>>temp;
    rating = rating + ' ' + temp;  //3

    readfile>>temp;  readfile>>temp;
    rating = rating + ' ' + temp; //2

    readfile>>temp;  readfile>>temp;
    rating = rating + ' ' + temp; //1

    readfile>>temp;
    while(temp!="导演"){
        readfile>>temp;
    }
    readfile>>temp;

    readfile>>director;
    readfile>>temp;
    while(temp!="编剧"){
        director += temp;
        readfile>>temp;
    }
    readfile>>temp;

    readfile>>writter;
    readfile>>temp;
    while(temp!="主演"){
        writter += temp;
        readfile>>temp;
    }
    readfile>>temp;

    readfile>>actor;
    readfile>>temp;
    while(temp!="类型:"){
        actor += temp;
        readfile>>temp;
    }

    readfile>>grene;
    readfile>>temp;
    while(temp!="制片国家/地区:"){
        grene += temp;
        readfile>>temp;
    }

    readfile>>area;
    readfile>>temp;
    while(temp!="语言:"){
        area += temp;
        readfile>>temp;
    }

    readfile>>language;
    readfile>>temp;
    while(temp!="首播:"){
        language += temp;
        readfile>>temp;
    }

    readfile>>date;
    readfile>>temp;
    while(temp!="季数:"){
        date += temp;
        readfile>>temp;
    }

    do{
        readfile>>temp;
        season++;
    }while(temp!="集数:");

    readfile>>episode;
    readfile>>temp;
    while(temp != "单集片长:"){
        episode += temp;
        readfile>>temp;
    }

    readfile>>runtime;
    readfile>>temp;
    while(temp != "IMDb链接:"){
        runtime += temp;
        readfile>>temp;
    }

    readfile.close();
    fclose(fopen(path.c_str(),"w"));
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
    _episode->setData(episode,in);
    _season->setData(std::to_string(season),in);


    simpleData.push_back(_TVname);
    simpleData.push_back(_grene);
    simpleData.push_back(_area);
    simpleData.push_back(_language);
    simpleData.push_back(_date);
    simpleData.push_back(_runtime);
    simpleData.push_back(_episode);
    simpleData.push_back(_season);
    simpleData.push_back(_actor);
    simpleData.push_back(_writter);
    simpleData.push_back(_director);
    simpleData.push_back(_rating);
}

void Tomato_TV_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    std::string path=PATH+"RottenTomatoes_by_TV.txt";

    initialTXT(path,_name);

    bas=new RottenTomatoes_by_TV();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
   std::string name,rating,actors, genre,network, date,temp;
    readfile>>temp;
    while(temp!="|"){
        name+=temp;
        name+=" ";
        readfile>>temp;
    }

    while(temp!="Fresh:"){
        readfile>>temp;
    }
    readfile>>rating;
    while(temp!="Average"){

        readfile>>temp;
    }
    readfile>>temp;
    rating+="% ";
    rating+=temp;
    readfile>>temp;
    readfile>>temp;
    readfile>>temp;
    while(temp!="Genre:"){
        actors+=temp;
        actors+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    while(temp!="Network:"){
        genre+=temp;
        genre+=" ";
        readfile>>temp;

    }
    readfile>>temp;
    while(temp!="Premiere"){
        network+=temp;
        network+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    readfile>>temp;
    while(temp!="Premiere"){
        date+=temp;
        date+=" ";
        readfile>>temp;
    }


    readfile.close();
    fclose(fopen(path.c_str(),"w"));
    delete bas;


    Input* in=new stdInput;
    Input* ins=new RTSinput;
    BaseData*_TVname=new TVplayName();
    BaseData*_rating=new RottenTomatoesScore();
    BaseData*_actors=new Intro();
    BaseData*_genre=new Type();
    BaseData*_network=new Studio();

    BaseData*_date=new ReleaseDate();


    _TVname->setData(name,in);
    _rating->setData(rating,ins);
    _actors->setData(actors,in);
    _genre->setData(genre,in);
    _network->setData(network,in);

    _date->setData(date,in);


    complexData.push_back(_actors);

    simpleData.push_back(_TVname);
    simpleData.push_back(_network);
    simpleData.push_back(_date);

    simpleData.push_back(_genre);
    simpleData.push_back(_rating);


}


void Imdb_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
     //样例ok

    std::string path=PATH+"IMDB_by_people.txt";
    initialTXT(path,_name);

    bas =new IMDB_by_people();
    bas->MakeCatcher();
    std::ifstream readfile=bas->SaveinBaseObject();
    std::string name,born_info,jobs,main_movies,temp;
    readfile>>temp;
    while(temp!="Born:"){
        name+=temp;
        name+=" ";
        readfile>>temp;
    }
    readfile>>temp;
    while(temp!="job:"){
        born_info+=temp;
        born_info+=" ";
        readfile>>temp;
    }
    readfile>>jobs;
    readfile>>temp;
    while(readfile>>temp){

        main_movies+=temp;
        main_movies+=" ";
    }
    fclose(fopen(path.c_str(),"w"));

    Input* in=new stdInput;
    BaseData*_peoplename =new PersonName();
    BaseData*_born_info=new BirthInfo();
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

    delete bas;

}
/*
void Douban_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {

    initialTXT("/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_people.txt",_name);

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

*/
void Tomato_people_Strategy::exec(std::string _name,std::vector<BaseData*> &complexData, std::vector<BaseData*> &simpleData) {
    //样例ok!!

    std::string path=PATH+"RottenTomatoes_by_people.txt";
    initialTXT(path, _name);

     bas = new RottenTomatoes_by_people();
     bas->MakeCatcher();
     std::ifstream readfile = bas->SaveinBaseObject();
     std::string name, birthday,birthplace, jobs, main_info, temp;
     readfile >> temp;
     readfile>>temp;
     while(temp!="|"){
         name+=temp;
         name+=" ";
         readfile>>temp;
     }
     readfile>>temp;
     readfile>>temp;
     while (temp != "Birthday:"){

         main_info += temp;
         main_info+=" ";
         readfile >> temp;
     }
     readfile>>temp;

     while (temp != "Birthplace:"){
         birthday += temp;
         birthday +=" ";
         readfile >> temp;

     }
     readfile>>temp;
     while(temp!="movies:"){
         birthplace+=temp;
         birthplace+=" ";
         readfile>>temp;
     }

     readfile.close();
     fclose(fopen(path.c_str(), "w"));

     Input *in = new stdInput;

     BaseData *_peoplename = new PersonName();
     BaseData *_birthday = new BirthDate();
     BaseData* _birthplace=new BirthPlace();
     BaseData *_main_info = new Intro();


     _peoplename->setData(name, in);
     _birthday->setData(birthday, in);
     _birthplace->setData(birthplace,in);

     _main_info->setData(main_info, in);


     simpleData.push_back(_peoplename);
     simpleData.push_back(_birthday);
     simpleData.push_back(_birthplace);

     simpleData.push_back(_main_info);

     delete bas;
}
