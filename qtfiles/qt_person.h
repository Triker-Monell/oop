#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QWidget>
#include "qt_details.h"
#include <QPushButton>
class Person : public Details
{
    Q_OBJECT
public slots:
    //slot is the difference
    //when more introduction pushed down
public:
    Person(QWidget* _central,QWidget* parent);
};

#endif // PERSON_H
