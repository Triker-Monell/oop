#ifndef _RANKING_H
#define _RANKING_H

#include <utility>
#include <vector>
#include <string>

#include "BaseObject.h"
class Ranking;
class SortStrategy{
public:
  virtual void work(Ranking* _rank)=0;
};

class RDSortStrategy : public SortStrategy{  //RELEASEDATE
public:
  void work(Ranking* _rank);     // sort RELEASEDATE ? 但目前传入的是一个按评分排序的排行榜，时间均为2016...
};

//可根据需要扩充其它的排序策略

class Ranking{
protected:
  std::vector<BaseObject*> rankings;
  //std::string type;
public:
  friend class SortStrategy;
  friend class RDSortStrategy;
  Ranking(){};
  void pushData(BaseObject* _object);
  void sort(SortStrategy* _strategy);
};



#endif
