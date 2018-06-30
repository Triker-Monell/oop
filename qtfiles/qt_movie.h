#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>
#include <QWidget>
#include "qt_details.h"
#include "qt_dbswidget.h"
class Movie : public Details
{
    Q_OBJECT
public:
    Movie(QString _name,QWidget* _central,QWidget* parent);
    ~Movie();
public slots:
    //slots is the diffence
};

#endif // MOVIE_H
