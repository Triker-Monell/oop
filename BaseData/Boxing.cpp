#include "Boxing.h"

void Boxing::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Boxing::showData(Output *out) const {
    return out->output(datas);
}