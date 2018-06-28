#include "Language.h"

void Language::setData(std::string, Input *in) {
    in->input(datas,data);
}

std::string Language::showData(Output *out) const {
    return out->output(datas);
}