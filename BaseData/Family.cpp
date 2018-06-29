#include "Family.h"


void Family::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Family::showData(Output *out) const {
    return out->output(datas);
}