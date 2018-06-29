#include "Sex.h"

void Sex::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Sex::showData(Output *out) const {
    return out->output(datas);
}