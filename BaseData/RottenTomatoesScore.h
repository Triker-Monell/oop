#ifndef ROTTENTOMATOESSCORE_H
#define ROTTENTOMATOESSCORE_H

#include "Score.h"
class RottenTomatoesScore:public Score{
    /*
     * 基类datas里
     * datas[0]为新鲜度  datas[1]为平均评分(满分为10)
     */
    double fresh;  //0-100
    double averagerating;
public:
    RottenTomatoesScore():Score("烂番茄评分"){};

    //这里将不使用stdInput和stdOutput  而是RTSinput 和RTSoutput
    /*
     * RTSinput格式
     *  85% Rating:7.6/10
     *
     * RTSoutput格式
     *  85%(Fresh) 7.6/10(AverageRating)
     *
     */
    void setData(std::string data,Input* in);
    std::string showData(Output* out)const;

    bool operator<(RottenTomatoesScore& right);
    bool operator>(RottenTomatoesScore& right);
    bool operator==(RottenTomatoesScore& right);

    double getFresh()const;
    double getAverageRating()const;
};

#endif