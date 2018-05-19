#include "TypeLanguage.h"

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