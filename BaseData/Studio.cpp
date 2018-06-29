#include "Studio.h"

void Studio::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Studio::showData(Output *out) const {
    out->output(datas);
}