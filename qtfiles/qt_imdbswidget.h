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

    //IMDB score (base data)

    QGridLayout* glayout;
public:
    IMDBSWidget(QWidget* parent=nullptr);
    void show();
    void hide();
};

#endif // QT_IMDBSWIDGET_H
