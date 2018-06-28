#include "Director.h"

void Director::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Director::showData(Output *out) const {
    return out->output(datas);
}