#include "Runtime.h"
#include <cctype>
void Runtime::setData(std::string data, Input *in) {
    in->input(datas,data);

    int i=0;
    int num=0;
    //std::cout << datas[0] << std::endl;
    while(data[i]>='0'&&data[i]<='9'){
        num=num*10+data[i]-'0';
        i++;
    }
    minute=num;
}

std::string Runtime::showData(Output *out) const {
    std::string str= out->output(datas);
    return str+"min";
}

bool Runtime::operator<(Runtime &right) {
    return minute<right.minute;
}

bool Runtime::operator>(Runtime &right) {
    return minute>right.minute;
}

bool Runtime::operator==(Runtime &right) {
    return minute==right.minute;
}