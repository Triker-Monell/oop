#ifndef QT_TV_H
#define QT_TV_H

#include <QWidget>
#include "qt_details.h"
class Tv : public Details
{
    Q_OBJECT
public:
    Tv(QString _name,QWidget* _central,QWidget* parent);
    ~Tv();
public slots:
    //slots is diff
};

#endif // QT_TV_H
