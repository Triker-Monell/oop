#include "Name.h"

void Name::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Name::showData(Output *out) const {
    return out->output(datas);
}