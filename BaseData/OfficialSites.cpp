#include "OfficialSites.h"

void OfficialSites::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string OfficialSites::showData(Output *out) const {
    return out->output(datas);
}