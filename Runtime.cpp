#include "Runtime.h"

void Runtime::setData(std::string newData) {
    minute=std::stoi(newData);
}

std::string Runtime::getData() const {
    return std::to_string(minute);
}

void Runtime::setMinute(int _min) {
    minute=_min;
}

int Runtime::getMinute() const {
    return minute;
}


bool operator>(const Runtime& right){
    return this->minute > right.minute;
}


bool Runtime::operator<(const Runtime& right){
    return this->minute<right.minute;
}

bool Runtime::operator==(const Runtime& right){
    return this->minute==right.minute;
}