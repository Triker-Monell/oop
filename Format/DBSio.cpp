#include "Format/DBSio.h"
#include <sstream>
void DBSinput::input(std::vector<std::string> &vec, std::string data) {
    std::stringstream ss;
    ss << data;
    ss >> vec[0];
    for(int i=MaxStar;i>=1;i--)
        ss >> vec[i];
}

std::string DBSoutput::output(const std::vector<std::string> &vec) {
    std::string back;
    back+="豆瓣评分"+vec[0];
    for(int i=MaxStar;i>=1;i--){
        back+=" " + char(i+'0');
        back+="星"+vec[i];
    }
    return back;
}