#ifndef DBSWIDGET_H
#define DBSWIDGET_H

#include <QObject>
#include <QWidget>
#include "qt_scorewidget.h"
#include <QLabel>
#include <vector>
#include <QGridLayout>
struct starline{
    QLabel* number;
    QLabel* image;
};

class DBSWidget : public ScoreWidget
{
    Q_OBJECT
private:
    QLabel* title; //DouBan Score
    QLabel* basescore;

    std::vector<starline> starvec; //show star

    //obj doubanscore;

    QGridLayout* glayout;

public:
    DBSWidget(QWidget* parent); //inital by a doubanscore!!
    void show();
    void hide();
};

#endif // DBSWIDGET_H
