#include "MovieType.h"

MovieType::MovieType(TypeLanguage *tlanguage,std::string _type):
        BaseData("MovieType","int"),typelanguage(tlanguage){
    type=tlanguage->searchNum(_type);
}


void MovieType::setData(std::string newData) {
    type=typelanguage->searchNum(newData);
}

void MovieType::setData_byMovieType(int _type) {
    type=_type;
}

std::string MovieType::getData() const {
    return typelanguage->getType(type);
}

std::string MovieType::getType(TypeLanguage *tl=typelanguage) const {
    return  tl->getType(type);
}

