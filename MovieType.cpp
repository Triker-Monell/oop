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


std::string ChineseTypeLanguage::getType(int num) {
    return ChineseType[num];
}


int ChineseTypeLanguage::searchNum(std::string _type) {
    for(int i=0;i<sizeof(ChineseType)/sizeof(ChineseType[0]);i++){
        if(_type==ChineseType[i]) return i;
    }
    return -1;
}

std::string EnglishTypeLanguage::getType(int num) {
    return EnglishType[num];
}

int EnglishTypeLanguage::searchNum(std::string _type) {
    for(int i=0;i<sizeof(EnglishType)/sizeof(EnglishType[0]);i++){
        if(_type==EnglishType[i]) return i;
    }
    return -1;
}