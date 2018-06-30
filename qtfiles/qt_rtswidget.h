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

    //obj

    QGridLayout* glayout;
public:
    RTSWidget(QWidget* parent=nullptr);
    void show();
    void hide();
};

#endif // QT_RTSWIDGET_H
