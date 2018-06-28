#include "qt_action.h"

Action::Action(const QString &text, QObject *parent):QAction(text,parent)
{
    connect(this,SIGNAL(triggered(bool)),this,SLOT(selftrigered()));
}

Action::Action(const QIcon &img, const QString &text, QObject *parent):
    QAction(img,text,parent)
{
    connect(this,SIGNAL(triggered(bool)),this,SLOT(selftrigered()));
}

void Action::selftrigered(){
    emit actrigered(this);
}
