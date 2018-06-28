#ifndef IMDBSCORE_H
#define IMDBSCORE_H

//IMDB评分
#include "BaseData.h"
#include "Score.h"
class IMDBScore:public Score{
    double points;
public:
    IMDBScore():Score("IMDB评分"){};

    //这里用IMDBSinput和IMDBSoutput
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    double getScore()const;

    //比较
    bool operator<(IMDBScore& right);
    bool operator>(IMDBScore& right);
    bool operator==(IMDBScore& right);
};

#endif