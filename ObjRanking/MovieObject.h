#ifndef _MOVIEOBJECT_H
#define _MOVIEOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"


class MovieObject : public BaseObject{
public:
    MovieObject(std::string _name,BaseStrategy* _strategy,std::string _type = "Movie"):
        BaseObject(_name,_strategy,_type){
        hasScore=true;
    }
    ~MovieObject(){}
};

#endif
