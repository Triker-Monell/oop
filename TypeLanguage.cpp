#include "TypeLanguage.h"

const std::string ChineseTypeLanguage::getType(int num) {
    return ChineseType[num];
}


int ChineseTypeLanguage::searchNum(std::string _type) {
    for(int i=0;i<sizeof(ChineseType)/sizeof(ChineseType[0]);i++){
        if(_type==ChineseType[i]) return i;
    }
    return -1;
}

const std::string EnglishTypeLanguage::getType(int num) {
    return EnglishType[num];
}

int EnglishTypeLanguage::searchNum(std::string _type) {
    for(int i=0;i<sizeof(EnglishType)/sizeof(EnglishType[0]);i++){
        if(_type==EnglishType[i]) return i;
    }
    return -1;
}

const std::string ChineseTypeLanguage::ChineseType[]={
        "喜剧", "冒险","奇幻","悬疑","惊悚",
         "纪录", "战争","西部","爱情","剧情",
         "恐怖", "动作","科幻","犯罪","传记",
         "历史", "运动"
};
const std::string EnglishTypeLanguage::EnglishType[]={
         "Comedy","Adventure","Fantasy","Mystery","Thriller",
         "Documentary","War","Western","Romance","Drama",
        "Horror","Action","ScienceFiction","Crime","Biography",
        "History","Sports"
};