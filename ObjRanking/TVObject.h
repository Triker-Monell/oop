#ifndef _TVOBJECT_H
#define _TVOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "Strategies.h"

class TVObject : public BaseObject{
public:
    TVObject(std::string _name,BaseStrategy* _strategy,std::string _type = "TV")
        :BaseObject(_name,_strategy,_type){
        hasScore=true;
    }
    ~TVObject(){}
};

#endif
