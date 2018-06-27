#ifndef _TVOBJECT_H
#define _TVOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "BaseData.h"
#include "Strategies.h"

class TVObject : public BaseObject{
public:
    TVObject(std::string _data, BaseStrategy* _strategy,std::string _type = "TV"){};
    ~TVObject(){};
};

#endif
