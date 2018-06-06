#ifndef IOFORMAT_H
#define IOFORMAT_H


#include <vector>
#include <string>
class Input{
public:
    virtual void input(std::vector<std::string>& vec,std::string data)=0;
};

class Output{
public:
    virtual std::string output(const std::vector<std::string>& vec)=0;
};


//派生类
/********************标准输入输出*********************/
/*
 * 多个数据之间以 / 分割
 */
class stdInput:public Input{
public:
    void input(std::vector<std::string>& vec,std::string data);
};

class stdOutput:public Output{
public:
    std::string output(const std::vector<std::string>& vec);
};

/****************************************************/


#endif