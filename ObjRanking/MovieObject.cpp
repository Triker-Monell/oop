#include "MovieObject.h"

MovieObject::MovieObject(std::string _name,BaseStrategy* _strategy):name(_name),type(_type){
  //_strategy 是 new之后 送进来的
  //BaseCatcher* _catcher = new BaseCatcher(_name);   //给爬虫名字，开始爬
  _strategy.exec(this->complexData, this->simpleData);  //爬虫用不同策略录入数据
  /*函数原型：catcher.Save...(std::vector<BaseData*>&, std::vector<BaseData*>&,BaseStrategy*)
    catcher 传一个大字符串， strategy 负责分隔 就地new BaseData 并且 push_back
  */
  //delete _catcher;    //销毁 爬虫与策略
  delete _strategy;
}
