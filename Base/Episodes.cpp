#include "Episodes.h"

void Episodes::setData(std::string data, Input *in) {
    in->input(datas,data);

    int i=0;
    int tmp=0;
    while(data[i]>='0'&&data[i]<='9'){
        tmp=tmp*10+data[i]-'0';
        i++;
    }
    number=tmp;
}

std::string Episodes::showData(Output *out) const {
    return out->output(datas);
}


bool Episodes::operator<(Episodes &right) {
    return number<right.number;
}


bool Episodes::operator>(Episodes &right) {
    return number>right.number;
}

bool Episodes::operator==(Episodes &right) {
    return number==right.number;
}