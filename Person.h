#ifndef _PERSON_H
#define _PERSON_H

#include"BaseData.h"

class Person:public BaseData{
private:
    std::string name;  //人名
    std::string sex; //male  female
    int age;
    std::string birthdate; //xxxx-xx-xx
    std::string birthplace;  //出生地
    std::string starsign; //星座
    std::vector<std::string> profession; //职业

    std::string source; //数据来源  填写网站
public:
    Person(std::string _dataname="Person"):BaseData(_dataname,"complex"),age(0){};
    void setName(std::string _name);
    std::string getName()const;
    void setSex(std::string _sex);
    std::string getSex()const;
    void setAge(int _age);
    int getAge()const;
    void setBirthDate(std::string _date);
    std::string getBirthDate()const;
    void setBirthplace(std::string _country);
    std::string getBirthplace()const;
    void setStarSign(std::string _starsign);
    std::string getStarSign()const;
    void setProfession(std::string _profession); //参数应该无空格，多个职业用/分割
    std::string getProfession()const; //返回值无空格，多个职业用/分割

    void setSource(std::string _source);
    std::string getSource()const;


    /*****************************/
    void setData(std::string) = delete;
    std::string getData()const = delete;
    /*******************************/
};

class Director:public Person{
public:
    Director():Person("Director"){};
};

class ScreenWriter:public Person{
public:
    ScreenWriter():Person("ScreenWriter"){};
};

class LeadingActor:public Person{
    std::string role; //扮演角色名
public:
    LeadingActor():Person("LeadingActor"){};

    void setRole(std::string _role);
    std::string getRole()const;
};

#endif