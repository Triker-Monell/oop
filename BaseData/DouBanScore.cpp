#include "DouBanScore.h"
#include <cmath>
void DouBanScore::setData(std::string data, Input *in) {
    in->input(datas,data);

    points[0]=std::stod(datas[0]);
    for(int i=1;i<=MaxStar;i++){
        std::string tmp;
        for(int k=0;k<datas[i].size()&&datas[i][k]>='0'&&datas[i][k]<='9';k++){
            tmp+=datas[i][k];
        }
        points[i]=std::stod(tmp)/100.0;
    }
}


std::string DouBanScore::showData(Output *out) const {
    return out->output(datas);
}


double DouBanScore::getScore() const {
    return points[0];
}

double DouBanScore::getRate(int star) const {
    if(star<=0||star>MaxStar) return -1;
    return points[star];
}

bool DouBanScore::operator<(DouBanScore &right) {
    return points[0]<right.points[0];
}

bool DouBanScore::operator>(DouBanScore &right) {
    return points[0]>right.points[0];
}

bool DouBanScore::operator==(DouBanScore &right) {
    return fabs(points[0]-right.points[0])<1e-6;
}