#include "Person.h"
#include <sstream>
void Person::setName(std::string _name) {
    name=_name;
}

std::string Person::getName() const {
    return name;
}

void Person::setSex(std::string _sex) {
    sex=_sex;
}

std::string Person::getSex() const {
    return sex;
}

void Person::setAge(int _age) {
    age=_age;
}

int Person::getAge() const {
    return age;
}

void Person::setBirthDate(std::string _date) {
    birthdate=_date;
}

std::string Person::getBirthDate() const {
    return birthdate;
}

void Person::setBirthplace(std::string _country) {
    birthplace=_country;
}

std::string Person::getBirthplace() const {
    return birthplace;
}

void Person::setStarSign(std::string _starsign) {
    starsign=_starsign;
}

std::string Person::getStarSign() const {
    return starsign;
}

void Person::setProfession(std::string _profession) {
    for(int i=0;i<_profession.length();i++){
        if(_profession[i]=='/')
            _profession[i]=' ';
    }
    std::stringstream ss;
    ss << _profession;
    std::string tmp;
    while(ss >> tmp){
        profession.push_back(tmp);
    }
}

std::string Person::getProfession() const {
    std::string result;
    for(int i=0;i<profession.size();i++){
        result+=profession[i];
        if(i!=profession.size()-1) result+='/';
    }
    return result;
}

void Person::setSource(std::string _source) {
    source=_source;
}

std::string Person::getSource() const {
    return source;
}

void LeadingActor::setRole(std::string _role) {
    role=_role;
}

std::string LeadingActor::getRole() const {
    return role;
}