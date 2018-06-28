#ifndef _MOVIEOBJECT_H
#define _MOVIEOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "BaseData.h"
#include "Strategies.h"

class MovieObject : public BaseObject{
public:
    MovieObject(std::string _name,BaseStrategy* _strategy,std::string _type = "Movie"){};
    ~MovieObject(){};
};

#endif
