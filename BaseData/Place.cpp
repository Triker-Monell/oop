#include "Place.h"

void FilmMakingArea::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string FilmMakingArea::showData(Output *out) const {
    return out->output(datas);
}

void BirthPlace::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string BirthPlace::showData(Output *out) const {
    return out->output(datas);
}