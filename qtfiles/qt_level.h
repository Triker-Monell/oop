#ifndef LEVEL_H
#define LEVEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "BaseData/allBaseData.h"
#include "Catcher/allCatcher.h"
//#include "qt_config.h"


class Level : public QWidget
{
    Q_OBJECT
public:
    Level(QWidget* _central,QWidget *parent,bool action_enable=true);
    virtual void show()=0; //show all
    virtual void hide()=0; //hide all
    virtual ~Level();
protected:
    QWidget* window; //mainwindow
    QWidget* central;
signals:
    void passLevel(Level* level); // pass the level pointer to the mainwindow's stack
public slots:
};
#endif // LEVEL_H
