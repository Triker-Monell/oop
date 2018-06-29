#include "Job.h"


void Job::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Job::showData(Output *out) const {
    return out->output(datas);
}