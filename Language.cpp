#include "Language.h"

void Language::setData(std::string newData) {
    language=newData;
}

std::string Language::getData() const {
    return language;
}