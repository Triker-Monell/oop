#include "Type.h"

void Type::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Type::showData(Output *out) const {
    return out->output(datas);
}