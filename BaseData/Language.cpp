#include "Language.h"

void Language::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Language::showData(Output *out) const {
    return out->output(datas);
}