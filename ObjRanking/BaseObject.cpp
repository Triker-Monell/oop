#include "BaseObject.h"

#include<utility>
#include<string>
#include<vector>

BaseObject::BaseObject(std::string _name,BaseStrategy* _strategy,std::string _type):name(_name),type(_type){
    _strategy->exec(complexData,simpleData);
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

const BaseData* BaseObject::queryData(std::string _type){  //类型：精确！
    std::vector<BaseData*>::iterator it;

//寻找type类型的数据
    for(it = complexData.begin();it != complexData.end();it++){
      std::string tmpType = (*it)->showType();
      if( tmpType == _type ){
        return (*it);
      }
    }

    for(it = simpleData.begin();it != simpleData.end();it++){
      std::string tmpType = (*it)->showType();
      if( tmpType == _type ){
        return (*it);
      }
    }

    return nullptr;  //error!
};

/*   OLD FUNCS, IGNORE THESE:   返工 浪费的代码
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
*/



/*
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
