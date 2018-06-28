#include "Format/IOFormat.h"
#include <iostream>
void stdInput::input(std::vector<std::string> &vec, std::string data) {
    for(int i=0;i<data.size();i++){
        std::string tmp;
        while(i<data.size()&&data[i]!='+') tmp+=data[i++];
        //std::cout << tmp << std::endl;
        vec.push_back(tmp);
    }
}


std::string stdOutput::output(const std::vector<std::string> &vec) {
    std::string back;
    for(int i=0;i<vec.size();i++){
        back+=vec[i];
        if(i!=vec.size()-1) back+='/';
    }
    return back;
}