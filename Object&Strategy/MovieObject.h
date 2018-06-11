#ifndef _MOVIEOBJECT_H
#define _MOVIEBJECT_H

#include <string>
#include <vector>

#include "BaseObject.h"
#include "BaseData.h"
#include "Strategies.h"

class MovieObject{
public:
    friend class BaseStrategy;
    friend class ImdbStrategy;
    friend class DoubanStrategy;
    friend class TomatoStrategy;

    MovieObject(std::string _data, BaseStrategy* _strategy,std::string _type = "Movie"){};

    //   MOVIE OBJECT 是否有对应的Movie 爬虫呢？？？？？？？？
};

#endif
