#ifndef ACTION_H
#define ACTION_H

#include <QObject>
#include <QWidget>
#include <QAction>
class Action : public QAction
{
    Q_OBJECT
public:
    Action(const QString &text, QObject *parent = nullptr);
    Action(const QIcon& img,const QString &text, QObject *parent = nullptr);
public slots:
    void selftrigered();
signals:
    void actrigered(Action* ac); //just in order to pass addr
};

#endif // ACTION_H
