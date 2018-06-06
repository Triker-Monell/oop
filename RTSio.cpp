#include "RTSio.h"
#include <sstream>

void RTSinput::input(std::vector<std::string> &vec, std::string data) {
    std::stringstream ss;
    ss << data;
    std::string fresh,ar;
    ss >> fresh >> ar;
    vec.push_back(fresh);
    vec.push_back(ar);
}


std::string RTSoutput::output(const std::vector<std::string> &vec) {
    std::string back;
    back+=vec[0]+"(Fresh)";
    back+=' '+vec[1]+"(AverageRating)";
    return back;
}