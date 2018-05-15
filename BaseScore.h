#ifndef _SCORE_H
#define _SCORE_H

#include "BaseData.h"
class BaseScore:public BaseData{
    double basescore;  //标准为1位小数 在不同的派生类中 basescore的含义不同 但都表示最普遍的评分
public:
    BaseScore(std::string _name="BaseScore",std::string _type="double"):
            BaseData(_name,_type),basescore(0){};
    BaseScore(double _basescore,std::string _name="BaseScore",std::string _type="double"):
            BaseData(_name,_type),basescore(_basescore){};

    void setScore(double _score);
    double getScore()const;

    //注意比较必须在同一个电影网站中的评分进行比较
    //因此需要提前判断是否为同一个电影网站
    //下列函数不判断是否为同一个电影网站
    friend bool operator>(const Score& right)const;
    friend bool operator<(const Score& right)const;
    friend bool operator==(const Score& right)const;

    friend istream& operator>>(istream& in,Score& right);
    friend ostream& operator<<(ostream& out,const Score& right)const;
};

#endif
