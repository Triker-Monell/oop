#include "qt_level.h"
#include "qt_config.h"
Level::Level(QWidget* _central, QWidget *parent, bool action_enable) :
    QWidget(parent),window(parent),central(_central)
{
    Config::instance().setAction(parent,action_enable);
}

Level::~Level(){

}
