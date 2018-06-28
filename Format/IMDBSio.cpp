#include "Format/IMDBSio.h"

void IMDBSinput::input(std::vector<std::string> &vec, std::string data) {
    //标准输入格式
    //(data)  rating: 8.8
    int i=0;
    while(i<data.size()&&(data[i]<'0'||data[i]>'9')) i++;

    if(i>=data.size()) return; //error!!!

    std::string points;
    while(i<data.size()&&(data[i]>='0'&&data[i]<='9'||data[i]=='.')) {
        points += data[i];
        i++;
    }
    vec.push_back(points);
}

std::string IMDBSoutput::output(const std::vector<std::string> &vec) {
    return vec[0]; //8.8
}