#include "Similar.h"


void SimilarMovie::setData(std::string data, Input *in) {
    in->input(datas,data):
}


std::string SimilarMovie::showData(Output *out) const {
    return out->output(datas);
}