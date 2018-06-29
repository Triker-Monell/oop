#include "Constellation.h"

void Constellation::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::String Constellation::showData(Output *out) const {
    return out->output(datas);
}