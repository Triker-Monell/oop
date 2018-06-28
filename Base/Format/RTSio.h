#ifndef RTSIO_H
#define RTSIO_H

#include "IOFormat.h"
/*
 * RTSinput格式
 *  85% 7.6/10
 *
 * RTSoutput格式
 *  85%(Fresh) 7.6/10(AverageRating)
 *
 */

    class RTSinput:public Input{
public:
    void input(std::vector<std::string>& vec,std::string data);
};

class RTSoutput:public Output{
public:
    std::string output(const std::vector<std::string>& vec);
};




#endif
