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

    const DouBanScore* dbscore; //obj

    QGridLayout* glayout;

public:
    DBSWidget(const Score* _score,QWidget* parent); //inital by a doubanscore!!
    void show();
    void hide();
};

#endif // DBSWIDGET_H
