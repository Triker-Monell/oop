#ifndef QT_RTSWIDGET_H
#define QT_RTSWIDGET_H

#include <QWidget>
#include "qt_scorewidget.h"
#include <QLabel>
#include <QGridLayout>
class RTSWidget : public ScoreWidget
{
    Q_OBJECT
private:
    QLabel* imagelabel;
    QLabel* freshlabel;
    QLabel* ratinglabel;

    const RottenTomatoesScore* score;

    QGridLayout* glayout;
public:
    RTSWidget(const Score* _score,QWidget* parent);
    void show();
    void hide();
};

#endif // QT_RTSWIDGET_H
