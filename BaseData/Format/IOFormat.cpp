#include "IOFormat.h"
#include <iostream>
void stdInput::input(std::vector<std::string> &vec, std::string data) {
    for(int i=0;i<data.size();i++){
        std::string tmp;
        while(i<data.size()&&data[i]!='/'&&data[i]!='|') tmp+=data[i++];
        //std::cout << tmp << std::endl;

        //filter
        int head=0,tail=tmp.size()-1;
        while(head<tmp.size()&&(tmp[head]==' '||tmp[head]=='/'||tmp[head]=='|')){
            head++;
        }
        while(tail>=0&&(tmp[head]==' '||tmp[head]=='/'||tmp[head]=='|')){
            tail--;
        }
        if(head>tail) continue; //如果error

        tmp=tmp.substr(head,tail-head+1);
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
