#include "Season.h"

void Season::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Season::showData(Output *out) const {
    return out->output(datas);
}