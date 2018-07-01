#include "RTSio.h"
#include <sstream>
#include <cctype>
void RTSinput::input(std::vector<std::string> &vec, std::string data) {
    std::stringstream ss;
    ss << data;
    std::string fresh,ar;
    ss >> fresh >> ar;

    int head=0,tail=ar.size()-1;
    while(head<ar.size()&&!isdigit(ar[head])) head++;
    while(tail>=0&&!isdigit(ar[tail])) tail--;
    ar=ar.substr(head,tail-head+1);
    vec.push_back(fresh);
    vec.push_back(ar);
}


std::string RTSoutput::output(const std::vector<std::string> &vec) {
    std::string back;
    back+=vec[0]+"(Fresh)";
    back+=' '+vec[1]+"(AverageRating)";
    return back;
}
