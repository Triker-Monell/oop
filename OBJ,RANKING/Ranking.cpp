#include "Ranking.h"

#include <utility>

void Ranking::pushData(BaseObject* _object){
  rankings.push_back(_object);
}

void Ranking::sort(SortStrategy* _strategy){
  _strategy->work();
}

void RDSortStrategy::work(){
  int num = rankings.size();

  std::vector<BaseData*> tmpDatas;
  tmpDatas.clear();
  for(int i=0; i<num; i++){
    tmpDatas.push_back(rankings[i]->queryData("上映日期"));
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
      if ( (*(datas[i])) > (*(datas[j]))){
        BaseData* tmp = tmpDatas[i];
        tmpDatas[i] = tmpDatas[j];
        tmpDatas[j] = tmp;
        int tmp1 = tmpLabel[i];
        tmpLabel[i] = tmpLabel[j];
        tmpLabel[j] = tmp1;
      }
    }
  }

  for (int i =0; i < num-1;i++){
    tmpObjects.push_back(rankings[tmpLabel[i]]);
  }

  for (int i =0; i< num-1;i++){
    rankings[i] = tmpObjects[i];
  }
}
