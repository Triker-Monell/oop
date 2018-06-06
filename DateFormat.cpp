#include "DateFormat.h"
#include <sstream>

std::tuple<int,int,int> stdDateFormat::getNum(std::string data) {
    std::string year,month,day;
    year=data.substr(0,4);
    month=data.substr(4,2);
    day=data.substr(6,2);
    return std::make_tuple(std::stoi(year),std::stoi(month),std::stoi(day));
}


std::tuple<int,int,int> EnglishDateFormat::getNum(std::string data) {
    std::string tmp;
    std::stringstream ss;
    int i=0;
    while(data[i]!=','){
        tmp+=data[i];
    }
    i++;
    std::string year,month,day;
    for(int k=0;k<4;k++,i++){
        year+=data[i];
    }
    ss << tmp;
    ss >> month >> day;

    return std::make_tuple(std::stoi(year),datemap[month],std::stoi(day));
}