#include "Type.h"

void Type::setData(std::string data, Input *in) {
    in->input(datas,data);
}

std::string Type::showData(Output *out) const {
    return out->output(datas);
}


bool Type::isType(std::string _type) {
    for(int i=0;i<datas.size();i++){
        if(_type==datas[i])
            return true;
    }
    return false;
}