#include "BriefIntroduction.h"

void BriefIntroduction::setData(std::string newData) {
    content=newData;
}

std::string BriefIntroduction::getData() const {
    return content;
}