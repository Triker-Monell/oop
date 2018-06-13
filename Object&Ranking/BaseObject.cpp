#include "BaseObject.h"

#include<string>
#include<vector>

BaseObject::BaseObject(std::string _name,BaseStrategy* _strategy,std::string _type):name(_name),type(_type){
  //_strategy 是 new之后 送进来的
  BaseCatcher* _catcher = new BaseCatcher(_name);   //给爬虫名字，开始爬
  _catcher.SaveinBaseObject(this->complexData, this->simpleData, _strategy);  //爬虫用不同策略录入数据
  /*函数原型：catcher.Save...(std::vector<BaseData*>&, std::vector<BaseData*>&,BaseStrategy*)
    catcher 传一个大字符串， strategy 负责分隔 就地new BaseData 并且 push_back
  */
  delete _catcher;    //销毁 爬虫与策略
  delete _strategy;
}

BaseObject::~BaseObject(){
    std::vector<BaseData*>::iterator it;
    for(it = complexData.begin();it != complexData.end();it++){
      delete *it;
    }
    for(it = simpleData.begin();it != simpleData.end();it++){
      delete *it;
    }
    complexData.clear();
    simpleData.clear();
};

std::string BaseObject::getName(){
  return name;
}

std::string BaseObject::getType(){
  return type;
}

int BaseObject::getComplexSize(){
  return complexData.size();
}

int BaseObject::getSimpleSize(){
  return simpleData.size();
}

const BaseData* BaseObject::func_clicked(int _num){
  return complexData[_num];
}

const BaseData* BaseObject::func_not_clicked(int _num){
  return simpleData[_num];
}


/*   OLD FUNCS, IGNORE THESE:
BaseObject* BaseObject::queryObj(std::string _data){
    std::vector<BaseData*>::iterator it;
    bool found = false;

    for(it = complexData.begin();it != complexData.end();it++){
      std::string tmpStr = (*it)->showData();
      std::string::size_type tmpIf = tmpStr.find(_data);
      if( tmpIf == std::string::npos ){
      }else{
        found = true;
        break;
      }
    }

    if(!found){
      for(it = simpleData.begin();it != simpleData.end();it++){
        std::string tmpStr = (*it)->showData();
        std::string::size_type tmpIf = tmpStr.find(_data);
        if( tmpIf == std::string::npos ){
        }else{
          found = true;
          break;
        }
      }
    }

    if(found) return this;
    return nullptr;
};

std::vector<std::string> BaseObject::queryStr(std::string _data){
    std::vector<BaseData*>::iterator it;
    std::vector<std::string> answers;
    answers.clear();

    for(it = complexData.begin();it != complexData.end();it++){
      std::string tmpStr = (*it)->showData();
      std::string::size_type tmpIf = tmpStr.find(_data);
      if( tmpIf == std::string::npos ){
      }else{
        answers.push_back(tmpStr);
      }
    }

    for(it = simpleData.begin();it != simpleData.end();it++){
      std::string tmpStr = (*it)->showData();
      std::string::size_type tmpIf = tmpStr.find(_data);
      if( tmpIf == std::string::npos ){
      }else{
        answers.push_back(tmpStr);
      }
    }

    if (answers.size() == 0){
      answers.push_back("No data.");
    }
    return answers;
}

std::vector<BaseData*> BaseObject::queryData(std::string _type){
    std::vector<BaseData*>::iterator it;
    std::vector<BaseData*> answers;
    answers.clear();

    for(it = complexData.begin();it != complexData.end();it++){
      std::string tmpType = (*it)->showType();
      if( tmpType == _type ){
        answers.push_back(*it);
      }
    }

    for(it = simpleData.begin();it != simpleData.end();it++){
      std::string tmpType = (*it)->showType();
      if( tmpType == _type ){
        answers.push_back(*it);
      }
    }

    if(answers.size() == 0){
      answers.push_back(nullptr);
    }
    return answers;
}

bool setData(BaseData* _basedata){
    std::string _type = _basedata->showType();
    std::vector<BaseData*>::iterator it;
    bool haveSet = false;
    for(it = complexData.begin();it != complexData.end();it++){
      if( (*it)->showType() == _type ){
        delete (*it);
        *it == _basedata;
        _basedata = nullptr;    //在外面new的BaseData 内部delete，新的数据由析构函数负责。
        haveSet = true;
        break;
      }
    }

    if(!haveSet){
      for(it = simpleData.begin();it != simpleData.end();it++){
        if( (*it)->showType() == _type ){
          delete (*it);
          *it == _basedata;
          _basedata = nullptr;    //在外面new的BaseData 内部delete，新的数据由析构函数负责。
          haveSet = true;
          break;
        }
      }
    }

    if(haveSet) return true;
    return false;
};

void pushData(Basedata* _basedata,bool isComplex){

};  // 新增一个元素


void sort(std::string _type);              //事物对象的排序
//   sort,show ,type: data , score?
//按照给出的排序原则把实例内部数据给排好序
//排好，返回这个实例，  不能点击放上面，能点击放下面
// baseobj -> sort -> 得分 /日期/XX

void BaseObject::setString(std::string _data, int num){
  stringData[num] = _data;
}

void BaseObject::pushComplex(BaseData* _data){
  complexData.push_back(_data);
}

void BaseObject::setComplex(std::string _data, BaseData* _basedata){
  _basedata->setData(_data,Input* in);
}
*/
