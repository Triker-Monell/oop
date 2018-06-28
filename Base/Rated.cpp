#include "Rated.h"

void Rated::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Rated::showData(Output *out) const {
    return out->output(datas);
}