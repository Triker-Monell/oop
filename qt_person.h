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

public:
    Person(QString _name, QWidget *_central, QWidget *parent);
    ~Person();
};

#endif // PERSON_H
