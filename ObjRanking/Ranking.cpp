#include "Ranking.h"

#include <utility>
#include <vector>

void Ranking::pushData(BaseObject* _object){
  rankings.push_back(_object);
}

void Ranking::sort(SortStrategy* _strategy){
  _strategy->work(this);
}

void RDSortStrategy::work(Ranking* _rank){
  int num = _rank->rankings.size();

  std::vector<const Date*> tmpDatas;
  tmpDatas.clear();
  for(int i=0; i<num; i++){
    tmpDatas.push_back(static_cast<const Date*>(_rank->rankings[i]->queryData("上映日期")));
  }

  std::vector<BaseObject*> tmpObjects;  //最后临时用一下。
  tmpObjects.clear();

  std::vector<int> tmpLabel;  //数字标记顺序
  tmpLabel.clear();
  for(int i=0;i<num;i++){
    tmpLabel.push_back(i);
  }


//sort
  for (int i = 0; i < num-1; i++){
    for (int j = i + 1; j < num-1; j++){
      if ( (*(tmpDatas[i])) > (*(tmpDatas[j]))){
        const Date* tmp = tmpDatas[i];
        tmpDatas[i] = tmpDatas[j];
        tmpDatas[j] = tmp;
        int tmp1 = tmpLabel[i];
        tmpLabel[i] = tmpLabel[j];
        tmpLabel[j] = tmp1;
      }
    }
  }

  for (int i =0; i < num-1;i++){
    tmpObjects.push_back(_rank->rankings[tmpLabel[i]]);
  }

  for (int i =0; i< num-1;i++){
    _rank->rankings[i] = tmpObjects[i];
  }
}
