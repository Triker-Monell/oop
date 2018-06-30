#include "Producer.h"


void Producer::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Producer::showData(Output *out) const {
    return out->output(datas);
}