#include "BirthInfo.h"

void BirthInfo::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string BirthInfo::showData(Output *out) const {
    return out->output(datas);
}