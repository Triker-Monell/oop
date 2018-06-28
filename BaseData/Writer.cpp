#include "Writer.h"

void Writer::setData(std::string data, Input *in) {
    in->input(datas,data);
}


std::string Writer::showData(Output *out) const {
    return out->output(datas);
}