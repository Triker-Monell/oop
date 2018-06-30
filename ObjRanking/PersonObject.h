#ifndef _PERSONOBJECT_H
#define _PERSONOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "Strategies.h"

class PersonObject : public BaseObject{
public:
    PersonObject(std::string _name, BaseStrategy* _strategy,std::string _type = "Person")
        :BaseObject(_name,_strategy,_type){
        hasScore=false;
    }
    ~PersonObject(){}
};

#endif
