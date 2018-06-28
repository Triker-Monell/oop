#ifndef _PERSONOBJECT_H
#define _PERSONOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "BaseData.h"
#include "Strategies.h"

class PersonObject : public BaseObject{
public:
    PersonObject(std::string _data, BaseStrategy* _strategy,std::string _type = "Person"){};
    ~PersonObject(){};
};

#endif
