#include "Date.h"
#include <iostream>
void Date::setDateNum(DateFormat *format) {
    //std::cout << datas[0] << std::endl;
    int y,m,d;
    std::tie(y,m,d)=format->getNum(datas[0]);
    year=y;
    month=m;
    day=d;
}


bool Date::operator<(Date& right) {
    if(year==right.year){
        if(month==right.month){
            return day<right.day;
        }
        return month<right.month;
    }
    return year<right.year;
}

bool Date::operator==(Date& right){
    return year==right.year&&month==right.month&&day==right.day;
}

bool Date::operator>(Date& right){
    return !(*this<right||*this==right);
}


void ReleaseDate::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string ReleaseDate::showData(Output *out) const {
    return out->output(datas);
}


void BirthDate::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string BirthDate::showData(Output *out) const {}