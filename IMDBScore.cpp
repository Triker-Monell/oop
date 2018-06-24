#include "IMDBScore.h"
#include <cmath>
void IMDBScore::setData(std::string data, Input *in) {
    in->input(datas,data);

    points=std::stod(datas[0]);
}

std::string IMDBScore::showData(Output *out) const {
    return out->output(datas);
}

double IMDBScore::getScore() const {
    return points;
}

bool IMDBScore::operator<(IMDBScore &right) {
    return points<right.points;
}

bool IMDBScore::operator>(IMDBScore &right) {
    return points>right.points;
}

bool IMDBScore::operator==(IMDBScore &right){
    return fabs(points-right.points)<1e-6;
}