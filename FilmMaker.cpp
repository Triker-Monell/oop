#include "FilmMaker.h"
void FilmMaker::setData(std::string newData) {
    CountryOrRegion=newData;
}

std::string FilmMaker::getData() const {
    return CountryOrRegion;
}