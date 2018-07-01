#ifndef QT_IMDBSWIDGET_H
#define QT_IMDBSWIDGET_H

#include <QWidget>
#include "qt_scorewidget.h"
#include <QLabel>
#include <QGridLayout>
class IMDBSWidget : public ScoreWidget
{
    Q_OBJECT
private:
    QLabel* imagelabel;
    QLabel* scorelabel;
    QLabel* maxscorelabel; //10

    const IMDBScore* imdbscore;

    QGridLayout* glayout;
public:
    IMDBSWidget(const Score* _score,QWidget* parent=nullptr);
    void show();
    void hide();
};

#endif // QT_IMDBSWIDGET_H
