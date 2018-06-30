#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QObject>
#include <QWidget>
#include "ObjRanking/allObj.h"
class ScoreWidget : public QWidget
{
    Q_OBJECT

protected:
    BaseObject* obj;
public:
    explicit ScoreWidget(QWidget *parent = nullptr);
    virtual void show()=0;
    virtual void hide()=0;
    virtual ~ScoreWidget();
signals:

public slots:
};

#endif // SCOREWIDGET_H
