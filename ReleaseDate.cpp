#include "ReleaseDate.h"

ReleaseDate::ReleaseDate(RDformat* _format,std::string date):
        BaseData("ReleaseDate","complex"),format(_format){
    std::tie(year,month,day,CountryOrRegion)=format->setRD(date);
}

void ReleaseDate::setData(std::string newData) {
    std::tie(year,month,day,CountryOrRegion)=format->setRD(newData);
}

std::string ReleaseDate::getData() const {
    return format->getRD(year,month,day,CountryOrRegion);
}

void ReleaseDate::setRD(std::string newData, RDformat *_format=format) {
    std::tie(year,month,day,CountryOrRegion)=format->setRD(newData);
}

std::string ReleaseDate::getRD(RDformat *_format) const {
    return format->getRD(year,month,day,CountryOrRegion);
}

void ReleaseDate::setYear(int _year) {
    year=_year;
}

std::string ReleaseDate::getYear() const {
    return std::to_string(year);
}

void ReleaseDate::setMonth(int _month) {
    month=_month;
}

std::string ReleaseDate::getMonth() const {
    return std::to_string(month);
}

void ReleaseDate::setDay(int _day) {
    day=_day;
}

std::string ReleaseDate::getDay() const {
    return std::to_string(day);
}

bool ReleaseDate::operator<(const ReleaseDate &right) const {
    if(this->year<right.year) return true;
    else if(this->year==right.year){
        if(this->month<right.month) return true;
        else if(this->month==right.month){
            if(this->day<right.day) return true;
        }
    }
    return false;
}

bool ReleaseDate::operator>(const ReleaseDate &right) const{
    bool eq;
    eq = this->year == right.year && this->month == right.month && this->day == right.day;
    return !(eq||*this<right);
}

bool ReleaseDate::operator==(const ReleaseDate &right) const{
    return this->year == right.year && this->month == right.month && this->day == right.day;
}


std::ostream& operator<<(std::ostream& out,const ReleaseDate& right)const{
    out << right.getData();
    return out;
}