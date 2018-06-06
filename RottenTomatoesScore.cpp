#include "RottenTomatoesScore.h"
#include <cmath>
void RottenTomatoesScore::setData(std::string data, Input *in) {
    in->input(datas,data);

    std::string freshstr,ar;
    for(int i=0;
        i<datas[0].size()&&((datas[0][i]>='0'&&datas[i][0]<='9')||datas[0][i]=='.');
        i++)
        freshstr+=datas[0][i];
    for(int i=0;i<datas[1].size()&&datas[1][i]!='/';i++)
        ar+=datas[1][i];

    fresh=std::stod(freshstr);
    averagerating=std::stod(ar);
}

std::string RottenTomatoesScore::showData(Output *out) const {
    return out->output(datas);
}

bool RottenTomatoesScore::operator<(RottenTomatoesScore &right) {
    if(fabs(fresh-right.fresh)<1e-6){
        return averagerating<right.averagerating;
    }
    return  fresh<right.fresh;
}

bool RottenTomatoesScore::operator==(RottenTomatoesScore &right) {
    return fabs(fresh-right.fresh)<1e-6&&fabs(averagerating-right.averagerating)<1e-6
}

bool RottenTomatoesScore::operator>(RottenTomatoesScore &right) {
    return !(*this<right||*this==right);
}

double RottenTomatoesScore::getFresh() const {
    return fresh;
}

double RottenTomatoesScore::getAverageRating() const {
    return averagerating;
}