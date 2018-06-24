#ifndef IMDBSIO_H
#define IMDBSIO_H

//IMDB评分格式
//rating: 8.8
#include "IOFormat.h

class IMDBSinput:public Input{
public:
    void input(std::vector<std::string>& vec,std::string data);
};


class IMDBSoutput:public Output{
public:
    std::string output(const std::vector<std::string>& vec);
};


#endif