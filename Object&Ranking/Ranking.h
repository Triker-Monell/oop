#ifndef _RANKING_H
#define _RANKING_H

#include <vector>
#include <string>

#include "BaseObject.h"

class SortStrategy{
public:
  virtual void work()=0;
};

class TimeSortStrategy : public SortStrategy{  //派生出其他策略亦可
public:
  work(){
    // sort RELEASE DATE ? 但time==2016！
  }
};

class Ranking{
protected:
  std::vector<BaseObject/* ????? */>  rankings;   //BaseObject 还是 tiny？
public:
  Ranking();       //暂未解决
  void sort(SortStrategy* _strategy){
    _strategy->work();
  }
  std::string showSingle(int num);
};

class MovieRanking : public Ranking{
  //??
};

class TVRanking : public Ranking{
  //??
};



#endif
