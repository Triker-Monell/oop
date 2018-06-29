#include "Intro.h"

void Intro::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Intro::showData(Output *out) const {
    return out->output(datas);
}