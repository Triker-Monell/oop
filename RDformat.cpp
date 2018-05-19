#include "RDformat.h"
std::tuple<int,int,int,std::string> DouBanRDformat::setRD(std::string newData) {
    //xxxx-xx-xx(xxxx)
    std::string y=newData.substr(0,4);
    std::string m=newData.substr(5,7);
    std::string d=newData.substr(8,10);
    std::string CorR=(newData.length()>10)? newData.substr(12,newData.length()-2):"";
    return std::make_tuple(std::stoi(y),std::stoi(m),std::stoi(d),CorR);
}

std::string DouBanRDformat::getRD(int year, int month, int day, std::string CountryorRegion) {
    std::string M= (month>=10)? std::to_string(month):"0"+std::to_string(month);
    std::string D= (day>=10)? std::to_string(day):"0"+std::to_string(day);
    std::string data=std::to_string(year)+"-"+M+"-"+D;
    if(CountryorRegion.length()>0) data+="("+CountryorRegion+")";
    return data;
}

std::tuple<int,int,int,std::string> RottenTomatoesRDformat::setRD(std::string newData) {
    //Apr 28,2018 Wide
    std::stringstream ss;
    for(int i=0;i<newData.length();i++){
        if(newData[i]==',') newData[i]=' ';
    }
    ss << newData;
    std::string y,m,d,CorR;
    ss >> m >> d >> y >> CorR;
    return std::make_tuple(std::stoi(y),std::stoi(m),std::stoi(d),CorR);
}

std::string RottenTomatoesRDformat::getRD(int year, int month, int day, std::string CountryorRegion) {
    std::string data=MONTH[month]+" "+std::to_string(day)+","+std::to_string(year);
    if(CountryorRegion.length()>0) data+= " " + CountryorRegion;
    return data;
}

