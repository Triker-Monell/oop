#ifndef _TVOBJECT_H
#define _TVOBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "BaseData.h"
#include "Strategies.h"

class TVObject{
public:
    friend class BaseStrategy;
    friend class ImdbStrategy;
    friend class DoubanStrategy;
    friend class TomatoStrategy;

    TVObject(std::string _data, BaseStrategy* _strategy,std::string _type = "TV"){};

    //   TV OBJECT 是否有对应的 TV 爬虫呢？？？？？？？？
};

#endif
