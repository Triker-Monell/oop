#ifndef LABEL_H
#define LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

//special label  using mouse event
class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent);
signals:
    void triggered(QString text);//when clicked
protected:
    void mousePressEvent(QMouseEvent* ev); //click
    //void mouseReleaseEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
};

#endif // LABEL_H
