#ifndef IMAGE_H
#define IMAGE_H

#include "BaseData.h"

//图片 存图片文件名称 只有一张图
class Image:public BaseData{
public:
    Image():BaseData("图片"){};
    void setData(std::string data);
    std::string showData()const;

};


#endif
