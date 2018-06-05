#include "LeadingActor.h"

void LeadingActor::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string LeadingActor::showData(Output *out) const {
    return out->output(datas);
}