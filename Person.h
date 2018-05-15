#ifndef _PERSON_H
#define _PERSON_H

#include"BaseData.h"

class Person:public BaseData{
private:
    std::string name;  //人名
    std::string sex; //male  female
    int age;
    std::string birthdate; //xxxx-xx-xx
    std::string country;  //出生地
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
    void setCountry(std::string _country);
    std::string getCountry()const;
};

class Director:public Person{
public:
    Director():Person("Director"){};
    void setData(std::string newData);
    std::string getData()const; //将数据都转换成string 以空格分割 然后返回
};

class ScreenWriter:public Person{
public:
    ScreenWriter():Person("ScreenWriter"){};
    void setData(std::string newData);
    std::string getData()const;
};

class LeadingActor:public Person{
    std::string role; //扮演角色名
public:
    LeadingActor():Person("LeadingActor"){};
    void setData(std::string newData);
    std::string getData()const;
    void setRole(std::string _role);
    std::string getRole()const;
};

#endif